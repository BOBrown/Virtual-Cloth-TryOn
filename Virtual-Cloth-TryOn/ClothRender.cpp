#include "stdafx.h"

#include "ClothRender.h"
#include "GLFunction.h"
#include "Virtual-Cloth-TryOnDoc.h"

#include "../Virtual-Cloth-TryOn-Data/DataCloth.h"
#include "../Virtual-Cloth-TryOn-Data/DataPattern.h"
#include "../Virtual-Cloth-TryOn-Data/DataCamera3D.h"
#include "../Virtual-Cloth-TryOn-Data/DataMaterial.h"
#include "../Virtual-Cloth-TryOn-Data/DataTexture.h"
#include <vector>


void ClothRender::DrawPattern(DataPattern* pattern)
{
	//if (!wall) return;
	//glColor3f(0, 0, 0);
	//glm::vec3 scale = wall->GetScale();
	//float rotate = wall->GetRotate();
	//glm::vec3 translate = wall->GetTranslate();
	//glPushMatrix();
	//glTranslatef(translate.x, translate.y, translate.z);
	//glRotatef(rotate, 0, 1, 0);
	//glScalef(scale.x, scale.y, scale.z);

	//GLFillNormCube();

	//glPopMatrix();
}

void ClothRender::DrawCloth(DataCloth* cloth)
{
	//if (!house) return;
	//std::vector<DataStraightWall*> walls = house->m_Walls;
	//for (std::vector<DataStraightWall*>::iterator it = walls.begin(); it != walls.end(); it++)
	//{
	//	DataStraightWall* wall = *it;
	//	DrawStraightWall(wall);
	//}
}

void ClothRender::Render()
{
	CVirtualClothTryOnDoc* doc = GetActiveDocument();//有了doc就有了绘制需要的数据文件	 
	if (!doc) return;

	SetupCamera(doc->m_pCamera3D);
	SetupRender();

	//下面可以测试绘制一些具体的图形
	GLDrawTriangle();
}

void ClothRender::SetupCamera(DataCamera3D* camera)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(camera->m_fViewAngle, camera->GetAspect(), camera->m_fNear, camera->m_fFar);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glLoadMatrixf(&camera->m_ViewMatrix[0][0]);
	glMultMatrixf(&camera->m_ModelMatrix[0][0]);
	//gluLookAt(camera->m_Eye.x, camera->m_Eye.y, camera->m_Eye.z,
	//	camera->m_LookAt.x, camera->m_LookAt.y, camera->m_LookAt.z,
	//	camera->m_Up.x, camera->m_Up.y, camera->m_Up.z);
	glViewport(0, 0, camera->m_fWidth, camera->m_fHeight);
}

void ClothRender::SetupRender()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_NORMALIZE);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);

	GLfloat ambientColor[] = { 0.1f, 0.1f, 0.1f, 1.0f }; //Color(0.2, 0.2, 0.2)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

	GLfloat lightColor0[] = { 0.5f, 0.5f, 0.5f, 1.0f }; //Color (0.5, 0.5, 0.5)
	GLfloat lightPos0[] = { 5000.0f, 5000.0f, 3000.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

	//Add directed light
	GLfloat lightColor1[] = { 0.5f, 0.2f, 0.2f, 1.0f };
	GLfloat lightPos1[] = { -0.5f, -0.5f, -0.5f, 0.0f };
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
	//assert(glGetError() == 0);
}

void ClothRender::SetupMaterial(DataMaterial* material)
{
	if (!material)
	{
		material = &DataMaterial();
	}
	if (material->m_DiffuseMap)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, material->m_DiffuseMap->m_iTextureID);
	}
	else
	{
		glDisable(GL_TEXTURE_2D);
	}
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,
		(float*)(&(material->m_Diffuse)));
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,
		(float*)(&(material->m_Ambient)));
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,
		(float*)(&(material->m_Specular)));
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS,
		material->m_fShininess);
}

void ClothRender::DrawMesh(DataMesh* mesh)
{
	glPushMatrix();//使得上次opengl变换对本次变换不产生影响
	// enable and specify pointers to vertex arrays
	if (mesh->m_vVertice)
	{
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, mesh->m_vVertice);
	}
	if (mesh->m_vNormal)
	{
		glEnableClientState(GL_NORMAL_ARRAY);
		glNormalPointer(GL_FLOAT, 0, mesh->m_vNormal);
	}
	if (mesh->m_vTexcoord)
	{
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(2, GL_FLOAT, 0, mesh->m_vTexcoord);
	}
	for (int iGroup = 0; iGroup < mesh->m_TriangleGroup.size(); iGroup++)
	{
		DataTriangleGroup* group = mesh->m_TriangleGroup[iGroup];
		if (!group || !group->m_iTriangleNumber)	continue;
		SetupMaterial(group->m_pMaterial);
		glDrawElements(GL_TRIANGLES, group->m_iTriangleNumber * 3, GL_UNSIGNED_INT, group->m_vTriangle);

	}

	if (mesh->m_vVertice)	glDisableClientState(GL_VERTEX_ARRAY);
	if (mesh->m_vNormal)	glDisableClientState(GL_NORMAL_ARRAY);
	if (mesh->m_vTexcoord)	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

	glPopMatrix();
	glPopName();
}
#include "stdafx.h"

#include "ClothRender.h"
#include "GLFunction.h"
#include "Virtual-Cloth-TryOnDoc.h"

#include "../Virtual-Cloth-TryOn-Data/DataCloth.h"
#include "../Virtual-Cloth-TryOn-Data/DataPattern.h"
#include "../Virtual-Cloth-TryOn-Data/DataCamera3D.h"
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
	gluPerspective(camera->m_fViewAngle, camera->m_fAspect, camera->m_fNear, camera->m_fFar);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(camera->m_Eye.x, camera->m_Eye.y, camera->m_Eye.z,
		camera->m_LookAt.x, camera->m_LookAt.y, camera->m_LookAt.z,
		camera->m_Up.x, camera->m_Up.y, camera->m_Up.z);
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
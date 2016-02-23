#include "stdafx.h"

#include "../dependencies/glm/detail/func_common.hpp"
#include "../dependencies/glm/glm.hpp"
#include "float.h"
#include <algorithm>
#include "DataMaterial.h"
#include "DataTexture.h"





//正确读取纹理所需函数
CString utilDirName(CString model_path)
{
	int p0 = model_path.ReverseFind('\\');
	int p1 = model_path.ReverseFind('\/');
	int p = (std::max)(p0, p1);
	return model_path.Mid(0, p);
}

glm::vec3 utilPointToVec3(CPoint pt)
{
	//return glm::vec3(pt.x, 0, pt.y);
	return glm::vec3(pt.x, pt.y, 0);
}
void utilMessageBox(CString message)
{
	AfxMessageBox(message, MB_OK);
}

float utilDistancePointSegment(glm::vec3 point, glm::vec3 segment_point1, glm::vec3 segment_point2)
{
	// Return minimum distance between line segment vw and point p
	glm::vec3 to = segment_point1 - segment_point2;
	const float l2 = to.x*to.x + to.z*to.z;  // i.e. |w-v|^2 -  avoid a sqrt
	if (l2 == 0.0) return glm::distance(point, segment_point1);   // v == w case
	// Consider the line extending the segment, parameterized as v + t (w - v).
	// We find projection of point p onto the line. 
	// It falls where t = [(p-v) . (w-v)] / |w-v|^2
	const float t = glm::dot(point - segment_point1, segment_point2 - segment_point1) / l2;
	if (t < 0.0) return glm::distance(point, segment_point1);       // Beyond the 'v' end of the segment
	else if (t > 1.0) return glm::distance(point, segment_point2);  // Beyond the 'w' end of the segment
	const glm::vec3 projection = segment_point1 + t * (segment_point2 - segment_point1);  // Projection falls on the segment
	return glm::distance(point, projection);
}
glm::vec3 utilProjectionPointSegment(glm::vec3 point, glm::vec3 segment_point1, glm::vec3 segment_point2)
{
	// Return minimum distance between line segment vw and point p
	glm::vec3 to = segment_point1 - segment_point2;
	const float l2 = to.x*to.x + to.z*to.z;  // i.e. |w-v|^2 -  avoid a sqrt
	// Consider the line extending the segment, parameterized as v + t (w - v).
	// We find projection of point p onto the line. 
	// It falls where t = [(p-v) . (w-v)] / |w-v|^2
	const float t = glm::dot(point - segment_point1, segment_point2 - segment_point1) / l2;
	const glm::vec3 projection = segment_point1 + t * (segment_point2 - segment_point1);  // Projection falls on the segment
	return projection;
}




DataMaterial* DataMaterial::LoadMaterialLibrary(CString filename, unsigned int& material_number)
{
	DataMaterial* materials = NULL;
	FILE* file = new FILE;
	char  buf[2048];
	unsigned int nummaterials;
	CString direcotry_name = utilDirName(filename);
	DataTexture* texture;
	/* open the file */
	fopen_s(&file, CStringA(filename), "r");
	if (!file) {
		CString file_not_found_message;
		//file_not_found_message.Format(IDS_FILE_NOT_FOUND);
		//file_not_found_message.Format(file_not_found_message, filename);
		//utilMessageBox(file_not_found_message);
		return NULL;
	}

	/* count the number of materials in the file */
	nummaterials = 1;
	while (fscanf_s(file, "%s", buf, sizeof(buf)) != EOF) {
		switch (buf[0]) {
		case '#':       /* comment */
			/* eat up rest of line */
			fgets(buf, sizeof(buf), file);
			break;
		case 'n':       /* newmtl */
			fgets(buf, sizeof(buf), file);
			nummaterials++;
			sscanf_s(buf, "%s", buf, sizeof(buf));
			break;
		default:
			/* eat up rest of line */
			fgets(buf, sizeof(buf), file);
			break;
		}
	}

	rewind(file);

	/* allocate memory for the materials */
	//materials = (DataMaterial*)malloc(sizeof(DataMaterial)* nummaterials);
	materials = new DataMaterial[nummaterials];
	material_number = nummaterials;

	/* now, read in the data */
	nummaterials = 0;
	while (fscanf_s(file, "%s", buf, sizeof(buf)) != EOF) {
		switch (buf[0]) {
		case '#':       /* comment */
			/* eat up rest of line */
			fgets(buf, sizeof(buf), file);
			break;
		case 'n':       /* newmtl */

			// Make sure the previous material has a name.
			//assert(materials[nummaterials].name);

			// Read in the new material name.
			fgets(buf, sizeof(buf), file);
			sscanf_s(buf, "%s", buf, sizeof(buf));
			nummaterials++;
			materials[nummaterials].m_strName = CString(buf);
			break;
		case 'N':
			fscanf_s(file, "%f", &materials[nummaterials].m_fShininess);
			break;
		case 'T': // Tr
			fscanf_s(file, "%f", &materials[nummaterials].m_fRefraction);
			break;
		case 'd': // d
			fscanf_s(file, "%f", &materials[nummaterials].m_fAlpha);
			break;
		case 'r': // reflectivity
			fscanf_s(file, "%f", &materials[nummaterials].m_fReflectivity);
			break;
		case 'e': // emissive
			fscanf_s(file, "%f %f %f",
				&materials[nummaterials].m_Emissive.x,
				&materials[nummaterials].m_Emissive.y,
				&materials[nummaterials].m_Emissive.z);
			break;
		case 'm':
		{
					char map_name[2048];
					// Check to see if we have scaled textures or not
					fscanf_s(file, "%s", map_name, sizeof(map_name));
					//TODO:加载纹理
					texture = DataTexture::LoadTexture(direcotry_name + CString("/") + CString(map_name));
					materials[nummaterials].m_DiffuseMap = texture;
		} // end case 'm'
			break;

		case 'K':
			switch (buf[1]) {
			case 'd':
				fscanf_s(file, "%f %f %f",
					&materials[nummaterials].m_Diffuse.x,
					&materials[nummaterials].m_Diffuse.y,
					&materials[nummaterials].m_Diffuse.z);
				break;
			case 's':
				fscanf_s(file, "%f %f %f",
					&materials[nummaterials].m_Specular.x,
					&materials[nummaterials].m_Specular.y,
					&materials[nummaterials].m_Specular.z);
				break;
			case 'a':
				fscanf_s(file, "%f %f %f",
					&materials[nummaterials].m_Ambient.x,
					&materials[nummaterials].m_Ambient.y,
					&materials[nummaterials].m_Ambient.z);
				break;
			default:
				/* eat up rest of line */
				fgets(buf, sizeof(buf), file);
				break;
			}
			break;
		default:
			/* eat up rest of line */
			fgets(buf, sizeof(buf), file);
			break;
		}
	}

	// Make sure we found the same number of materials the second time around.
	// Note that glm adds a default material to the beginning of the array
	assert((nummaterials + 1) == material_number);
	fclose(file);
	return materials;
}

DataMaterial::DataMaterial()
{
	//m_strName.Format(IDS_DEFAULT_MATERIAL_NAME);
	m_Diffuse = glm::vec4(1.0f);
	m_Ambient = glm::vec4(0.2f, 0.2f, 0.2f, 1.0f);
	m_Specular = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_Emissive = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);

	m_fShininess = 0;
	m_fRefraction = 1;
	m_fAlpha = 1;
	m_fReflectivity = 0;

	m_AmbientMap = NULL;
	m_DiffuseMap = NULL;
	m_SpecularMap = NULL;

}

DataMaterial::~DataMaterial()
{

}



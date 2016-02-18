#ifndef _VIRTUAL_CLOTH_TRYON_DATA_MESH_H_
#define _VIRTUAL_CLOTH_TRYON_DATA_MESH_H_

#include "BaseExport.h"
#include "../dependencies/glm/vec3.hpp"
//#include "HouseData/DataBoundingBox3D.h"
//#include "HouseData/DataID.h"
#include <vector>

class DataMaterial;
class CLOTH_DATA_DLL DataTriangleGroup
{
public:
	DataTriangleGroup();
	DataTriangleGroup(int number);
	~DataTriangleGroup();
public:
	glm::uvec3*		m_vTriangle;
	int				m_iTriangleNumber;
	DataMaterial*	m_pMaterial;
};
class CLOTH_DATA_DLL DataMesh
{
public:
	DataMesh();
	~DataMesh();
public:
	glm::vec3*		m_vVertice;      /* array of vertices
									 [x1,y1,z1,x2,y2,z2...] */
	glm::vec3*		m_vNormal;      /* array of normals */

	glm::vec2*		m_vTexcoord;      /* array of texture coordinates */

	int				m_iVertexNumber;

	std::vector<DataTriangleGroup*>	m_TriangleGroup;

	//DataBoundingBox3D	m_BoundingBox;
public:
	static DataMesh*	LoadMesh(CString file_name);

	friend class HouseRender2D;
	friend class HouseRender3D;
};
#endif
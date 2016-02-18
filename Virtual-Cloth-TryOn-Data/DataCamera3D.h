#ifndef _VIRTUAL_CLOTH_TRYON_DATA_CAMERA_3D_H_
#define _VIRTUAL_CLOTH_TRYON_DATA_CAMERA_3D_H_
#include "../dependencies/glm/vec3.hpp"
#include "BaseExport.h"

class CLOTH_DATA_DLL DataCamera3D
{
public:
	glm::vec3 m_LookAt;	
	glm::vec3 m_Eye;
	glm::vec3 m_Up;
	float		m_fViewAngle;
	float		m_fAspect;
	float		m_fNear;
	float		m_fFar;
public:
	DataCamera3D();
};
#endif
#ifndef _VIRTUAL_CLOTH_TRYON_DATA_CAMERA_3D_H_
#define _VIRTUAL_CLOTH_TRYON_DATA_CAMERA_3D_H_
#include "../dependencies/glm/vec3.hpp"
#include "BaseExport.h"
#include "../dependencies/glm/glm.hpp"

class CLOTH_DATA_DLL DataCamera3D
{
public:
	glm::vec3 m_LookAt;	
	glm::vec3 m_Eye;
	glm::vec3 m_Up;

	glm::mat4 m_ViewMatrix;
	glm::mat4 m_ModelMatrix;

	float		m_fWidth;
	float		m_fHeight;


	float		m_fViewAngle;
	float		m_fAspect;
	float		m_fNear;
	float		m_fFar;
public:
	DataCamera3D();
	void  SetSize(float width, float height);
	float GetAspect();
};
#endif
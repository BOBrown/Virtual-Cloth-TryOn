#include "stdafx.h"
#include "DataCamera3D.h"

DataCamera3D::DataCamera3D()
{
	m_LookAt = glm::vec3(0, 0, 0);
	//m_Eye = glm::vec3(500, 6500, 500);
	m_Eye = glm::vec3(0, 0, 10000);
	m_Up = glm::uvec3(0, 1, 0);
	m_fViewAngle = 60;
	m_fAspect = 1;
	m_fNear = 10;
	m_fFar = 100000;
}
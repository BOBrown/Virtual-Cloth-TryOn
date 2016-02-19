#include "stdafx.h"
#include "DataCamera3D.h"
#include "../glm/gtc/matrix_transform.hpp"
#include "../glm/gtx/transform.hpp"

DataCamera3D::DataCamera3D()
{
	m_LookAt = glm::vec3(0, 0, 0);
	//m_Eye = glm::vec3(500, 6500, 500);
	m_Eye = glm::vec3(0, 0, 10000);
	m_Up = glm::uvec3(0, 1, 0);

	m_ViewMatrix = glm::lookAt(m_Eye, m_LookAt, m_Up);
	m_ModelMatrix = glm::mat4(1.0f);


	m_fViewAngle = 60;
	m_fAspect = 1;
	m_fNear = 10;
	m_fFar = 100000;
}
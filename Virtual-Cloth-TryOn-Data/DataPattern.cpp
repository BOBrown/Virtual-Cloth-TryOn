#include "stdafx.h"
#define _USE_MATH_DEFINES
#include "math.h"
#include "DataPattern.h"
#include "../Virtual-Cloth-TryOn/GLFunction.h"
#include "../dependencies/glm/glm.hpp"

DataPattern::DataPattern(glm::vec3 pt1, glm::vec3 pt2) :m_ptFirst(pt1), m_ptSecond(pt2)
{
	m_fHeight = 2800.0f;
	m_fThickness = 120.0f;
	m_fFloorLineHeight = 0.0f;
}





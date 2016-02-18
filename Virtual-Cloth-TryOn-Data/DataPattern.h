#ifndef _VIRTUAL_CLOTH_TRYON_DATA_PATTERN_H_
#define _VIRTUAL_CLOTH_TRYON_DATA_PATTERN_H_

#include "DataCamera3D.h"
#include "DataBase.h"
#include "DataMesh.h"
#include "../dependencies/glm/vec3.hpp"

class CLOTH_DATA_DLL DataPattern :public DataBase
{
public:
	DataPattern(glm::vec3 pt1, glm::vec3 pt2);
	//TODO:
	//要考虑墙的绘制，以及在墙上不同区域贴纹理
private:
	float			m_fHeight;
	float			m_fThickness;
	float			m_fFloorLineHeight;
	glm::vec3		m_ptFirst;
	glm::vec3		m_ptSecond;

	int				m_iMode;

public:


public:
	//virtual void	Draw(CDC* pDC);
};
#endif
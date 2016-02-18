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
	//Ҫ����ǽ�Ļ��ƣ��Լ���ǽ�ϲ�ͬ����������
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
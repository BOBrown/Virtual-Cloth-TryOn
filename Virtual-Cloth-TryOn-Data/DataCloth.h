#ifndef _VIRTUAL_CLOTH_TRYON_DATA_CLOTH_H_
#define _VIRTUAL_CLOTH_TRYON_DATA_CLOTH_H_

#include "BaseExport.h"
#include "DataBase.h"
#include <vector>

class DataPattern;

class CLOTH_DATA_DLL DataCloth :public DataBase
{
public:
	DataCloth(void);
public:
	std::vector<DataPattern*>	m_Cloths;

	friend class HouseRender2D;
};
#endif
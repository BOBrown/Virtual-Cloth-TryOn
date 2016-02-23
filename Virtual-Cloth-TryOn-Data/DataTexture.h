#ifndef _VIRTUAL_CLOTH_TRYON_DATA_TEXTURE_H_
#define _VIRTUAL_CLOTH_TRYON_DATA_TEXTURE_H_
#include <iostream>
#include "BaseExport.h"
class CLOTH_DATA_DLL DataTexture
{
public:
	unsigned int m_iWidth;
	unsigned int m_iHeight;
	unsigned int m_iTextureID;
	unsigned int m_iFormat;
	CString	 m_strName;
public:
	DataTexture();
	static DataTexture* LoadTexture(CString file_name);
};
#endif
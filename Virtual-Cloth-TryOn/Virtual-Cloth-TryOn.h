
// Virtual-Cloth-TryOn.h : Virtual-Cloth-TryOn Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CVirtualClothTryOnApp:
// �йش����ʵ�֣������ Virtual-Cloth-TryOn.cpp
//

class CVirtualClothTryOnApp : public CWinAppEx
{
public:
	CVirtualClothTryOnApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CVirtualClothTryOnApp theApp;

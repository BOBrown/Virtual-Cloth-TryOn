// View3D.cpp : 实现文件
//

#include "stdafx.h"
#include "Virtual-Cloth-TryOn.h"
#include "View3D.h"


// HouseView3D

IMPLEMENT_DYNCREATE(View3D, CView)

View3D::View3D()
{

}

View3D::~View3D()
{
}

BEGIN_MESSAGE_MAP(View3D, CView)
END_MESSAGE_MAP()


// HouseView3D 绘图

void View3D::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	pDC->Ellipse(100, 100, 1000, 1000);
}


// HouseView3D 诊断

#ifdef _DEBUG
void View3D::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void View3D::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// HouseView3D 消息处理程序
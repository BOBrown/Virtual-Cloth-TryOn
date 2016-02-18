// View3D.cpp : 实现文件
//

#include "stdafx.h"
#include "Virtual-Cloth-TryOn.h"
#include "View3D.h"
#include "OpenGLView.h"
#include "../dependencies/include/gl/GL.h"
#include "GLFunction.h"
#include "ClothRender.h"


// HouseView3D

IMPLEMENT_DYNCREATE(View3D, OpenGLView)

View3D::View3D()
{

}

View3D::~View3D()
{
}

BEGIN_MESSAGE_MAP(View3D, OpenGLView)
END_MESSAGE_MAP()


// HouseView3D 绘图

void View3D::OnDraw(CDC* pDC)
{

	SceneBegin();

	ClothRender render;
	render.Render();

	SceneFlip();
	SceneEnd();
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
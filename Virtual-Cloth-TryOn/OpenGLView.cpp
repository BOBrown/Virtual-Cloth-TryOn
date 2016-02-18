#include "stdafx.h"
#include "resource.h"
#include "OpenGLView.h"
#include "GLFunction.h"

BEGIN_MESSAGE_MAP(OpenGLView, CView)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

BOOL OpenGLView::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.style |= (WS_CLIPCHILDREN | WS_CLIPSIBLINGS);
	return CView::PreCreateWindow(cs);
}
int OpenGLView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	if (SetWindowPixelFormat() == FALSE)
	{
		return 0;
	}
	if (!SceneBegin())
		return FALSE;
	return 0;
}

BOOL OpenGLView::SetWindowPixelFormat()
{
	HWND hWnd = this->GetSafeHwnd();
	HDC hDC = ::GetDC(hWnd);
	PIXELFORMATDESCRIPTOR pixelDesc =
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL |
		PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		24,
		0, 0, 0, 0, 0, 0,
		0,
		0,
		0,
		0, 0, 0, 0,
		32,
		0,
		0,
		PFD_MAIN_PLANE,
		0,
		0, 0, 0
	};
	int pixel_index = ChoosePixelFormat(hDC, &pixelDesc);
	if (pixel_index == 0)
	{
		pixel_index = 1;
		if (DescribePixelFormat(hDC, pixel_index, sizeof(PIXELFORMATDESCRIPTOR), &pixelDesc) == 0)
		{
			return FALSE;
		}
	}

	if (SetPixelFormat(hDC, pixel_index, &pixelDesc) == FALSE)
	{
		return FALSE;
	}
	return TRUE;
}
BOOL OpenGLView::SceneBegin()
{
	HWND hWnd = this->GetSafeHwnd();
	HDC hDC = ::GetDC(hWnd);
	if (g_GLContext == NULL)
	{
		g_GLContext = wglCreateContext(hDC);
	}
	if (g_GLContext == NULL)
	{
		return FALSE;
	}

	if (wglMakeCurrent(hDC, g_GLContext) == FALSE)
	{
		return FALSE;
	}

	return TRUE;
}

BOOL OpenGLView::SceneEnd()
{
	if (wglGetCurrentContext() != NULL)
	{
		wglMakeCurrent(NULL, NULL);
	}
	return TRUE;
}
BOOL OpenGLView::SceneFlip()
{
	HWND hWnd = this->GetSafeHwnd();
	HDC hDC = ::GetDC(hWnd);

	return SwapBuffers(hDC);
}

void OpenGLView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	SetViewPort(cx, cy);
}

BOOL OpenGLView::SetViewPort(int cx, int cy)
{
	int width, height;
	double aspect;
	width = cx;
	height = cy;
	if (cy == 0)
	{
		aspect = (double)width;
	}
	else
	{
		aspect = (double)width / (double)height;
	}
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, cx, 0.0, cy);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	return true;
}

glm::vec3 OpenGLView::point_to_vec3(CPoint point)
{
	CRect rect;
	GetClientRect(&rect);
	glm::vec3 pt(point.x, rect.Height() - point.y, 0);
	return pt;
}
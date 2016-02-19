// View3D.cpp : ʵ���ļ�
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
	//ON_WM_SIZE()//���ڴ�С�仯ʱ��������Ӧ�߼�����
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_WM_MBUTTONDOWN()
	ON_WM_MBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_KEYDOWN()
	ON_WM_MOUSEWHEEL()
	ON_WM_TIMER()
END_MESSAGE_MAP()


//View3D ��ͼ
//�ĵ���Ҫˢ��ʱ��ϵͳ���Զ����øú���
void View3D::OnDraw(CDC* pDC)
{
	//mfc�п���opengl����ģʽ
	SceneBegin();

	//opengl����Ļ��Ʋ�������ר�ŵ�һ����������
	ClothRender render;
	render.Render();


	//mfc��opengl����ģʽ��������
	SceneFlip();
	SceneEnd();
}		


//View3D ���

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


//View3D ��Ϣ�������
void View3D::OnSize(UINT nType, int cx, int cy)
{
	//OpenGLView::OnSize(nType, cx, cy);
	//float aspect = (float)cy / cx;
	//DataCamera3D* camera = m_pDataManager->m_pCamera3D;
	//camera->SetSize(cx, cy);
	//Render();
}

void View3D::OnLButtonDown(UINT nFlags, CPoint point)
{
	OpenGLView::OnLButtonDown(nFlags, point);
	SceneBegin();
	/*glm::vec3 vec = glm::vec3(point.x, point.y, 0);
	DATA_ID_TYPE id = Selector::GetInstance()->Select(vec);
	DataID* object = DataID::GetObject(id);
	DataType data_type = object->GetDataType();*/
	//m_OperationDispatcher3D.OnLButtonDown(nFlags, glm::vec3(point.x, point.y, 0));
	SendMessage(WM_PAINT);
}

void View3D::OnRButtonDown(UINT nFlags, CPoint point)
{
	OpenGLView::OnRButtonDown(nFlags, point);

	//m_OperationDispatcher3D.OnRButtonDown(nFlags, glm::vec3(point.x, point.y, 0));
	SendMessage(WM_PAINT);
}

void View3D::OnRButtonUp(UINT nFlags, CPoint point)
{
	OpenGLView::OnRButtonUp(nFlags, point);

	//m_OperationDispatcher3D.OnRButtonUp(nFlags, glm::vec3(point.x, point.y, 0));
	SendMessage(WM_PAINT);
}

void View3D::OnMButtonDown(UINT nFlags, CPoint point)
{
	OpenGLView::OnMButtonDown(nFlags, point);

	//m_OperationDispatcher3D.OnMButtonDown(nFlags, glm::vec3(point.x, point.y, 0));
	SendMessage(WM_PAINT);
}

void View3D::OnMButtonUp(UINT nFlags, CPoint point)
{
	OpenGLView::OnMButtonUp(nFlags, point);

	//m_OperationDispatcher3D.OnMButtonUp(nFlags, glm::vec3(point.x, point.y, 0));
	SendMessage(WM_PAINT);
}

void View3D::OnMouseMove(UINT nFlags, CPoint point)
{
	OpenGLView::OnMouseMove(nFlags, point);

	//m_OperationDispatcher3D.OnMouseMove(nFlags, glm::vec3(point.x, point.y, 0));
	SendMessage(WM_PAINT);
}

void View3D::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	OpenGLView::OnKeyDown(nChar, nRepCnt, nFlags);
	//m_OperationDispatcher3D.OnKeyDown(nChar, nRepCnt, nFlags);
	SendMessage(WM_PAINT);
}

BOOL View3D::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	OpenGLView::OnMouseWheel(nFlags, zDelta, pt);

	//m_OperationDispatcher3D.OnMouseWheel(nFlags, zDelta, pt);
	SendMessage(WM_PAINT);
	return TRUE;
}

void View3D::OnTimer(UINT_PTR nIDEvent)
{
	OpenGLView::OnTimer(nIDEvent);
	//m_OperationDispatcher3D.OnTimer(nIDEvent);
	SendMessage(WM_PAINT);
}
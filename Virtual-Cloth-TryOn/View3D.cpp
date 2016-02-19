// View3D.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Virtual-Cloth-TryOn.h"
#include "Virtual-Cloth-TryOnDoc.h"
#include "View3D.h"
#include "OpenGLView.h"
#include "../dependencies/include/gl/GL.h"
#include "GLFunction.h"
#include "../Virtual-Cloth-TryOn-Data/DataCamera3D.h"


#include "../dependencies/glm/gtc/matrix_transform.hpp"
#include "../dependencies/glm/gtx/transform.hpp"
#include "../dependencies/glm/gtc/matrix_inverse.hpp"


//View3D

IMPLEMENT_DYNCREATE(View3D, OpenGLView)

View3D::View3D()
{
	m_iOperationView = OPERATIONVIEW_NONE;
}

View3D::~View3D()
{
}

BEGIN_MESSAGE_MAP(View3D, OpenGLView)
	ON_WM_SIZE()//���ڴ�С�仯ʱ��������Ӧ�߼�����
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
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
	m_Render.Render();


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
	OpenGLView::OnSize(nType, cx, cy);
	float aspect = (float)cy / cx;

	CVirtualClothTryOnDoc* doc = GetActiveDocument();//����doc�����˻�����Ҫ�������ļ�	 
	if (!doc) return;

	DataCamera3D* camera = doc->m_pCamera3D;
	camera->SetSize(cx, cy);
	m_Render.Render();
}

void View3D::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_LastPt = glm::vec3(point.x, point.y, 0);
	m_iOperationView = OPERATIONVIEW_ROTATE;
	SendMessage(WM_PAINT);
}

void View3D::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_LastPt = glm::vec3(point.x, point.y, 0);
	m_iOperationView = OPERATIONVIEW_NONE;
	SendMessage(WM_PAINT);
}

void View3D::OnRButtonDown(UINT nFlags, CPoint point)
{
	m_LastPt = glm::vec3(point.x, point.y, 0);
	m_iOperationView = OPERATIONVIEW_TRANSLATE;
	SendMessage(WM_PAINT);
}

void View3D::OnRButtonUp(UINT nFlags, CPoint point)
{
	m_LastPt = glm::vec3(point.x, point.y, 0);
	m_iOperationView = OPERATIONVIEW_NONE;
	SendMessage(WM_PAINT);
}

void View3D::OnMButtonDown(UINT nFlags, CPoint point)
{
	SendMessage(WM_PAINT);
}

void View3D::OnMButtonUp(UINT nFlags, CPoint point)
{
	SendMessage(WM_PAINT);
}

void View3D::OnMouseMove(UINT nFlags, CPoint point)
{
	switch (m_iOperationView)
	{
	case OPERATIONVIEW_ROTATE://���������ת��ͼ 
		OnLButtonMouseMove(nFlags, point);
		break;
	case OPERATIONVIEW_TRANSLATE://����	����ƽ��ͼ 
		OnRButtonMouseMove(nFlags, point);
		break;
	default:
		break;
	}


	SendMessage(WM_PAINT);
}

void View3D::OnRButtonMouseMove(UINT nFlags, CPoint point)
{
	glm::vec3 tmp_point = glm::vec3(point.x, point.y, 0);

	glm::vec3 translate = tmp_point - m_LastPt;
	float dx = translate.x;
	float dy = translate.y;

	CVirtualClothTryOnDoc* doc = GetActiveDocument();//����doc�����˻�����Ҫ�������ļ�	 
	assert(doc);
	DataCamera3D* camera = doc->m_pCamera3D;

	camera->m_ViewMatrix = glm::translate(glm::vec3(dx, -dy, 0)) * camera->m_ViewMatrix;

	m_LastPt = glm::vec3(point.x, point.y, 0);
}

void View3D::OnLButtonMouseMove(UINT nFlags, CPoint point)
{
	glm::vec3 tmp_point = glm::vec3(point.x, point.y, 0);//��ȡlasteye����ϵ��point����
	glm::vec3 translate = tmp_point - m_LastPt;
	float dx = translate.x;
	float dy = translate.y;

	CVirtualClothTryOnDoc* doc = GetActiveDocument();//����doc�����˻�����Ҫ�������ļ�	 
	assert(doc);
	DataCamera3D* camera = doc->m_pCamera3D;

	camera->m_ViewMatrix *= glm::rotate(dx*0.002f, glm::vec3(0, 1, 0));
	glm::vec3 v = glm::vec3(glm::affineInverse(camera->m_ViewMatrix)*glm::vec4(1, 0, 0, 0));
	camera->m_ViewMatrix *= glm::rotate(dy*0.002f, v);

	m_LastPt = glm::vec3(point.x, point.y, 0);
}

void View3D::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	SendMessage(WM_PAINT);
}

BOOL View3D::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	CVirtualClothTryOnDoc* doc = GetActiveDocument();//����doc�����˻�����Ҫ�������ļ�	 
	assert(doc);
	DataCamera3D* camera = doc->m_pCamera3D;


	float speed_scale = zDelta;
	camera->m_ViewMatrix = glm::translate(glm::vec3(0, 0, speed_scale)) * camera->m_ViewMatrix;


	SendMessage(WM_PAINT);
	return TRUE;
}

void View3D::OnTimer(UINT_PTR nIDEvent)
{
	SendMessage(WM_PAINT);
}

glm::vec3 View3D::Conv2Dto3D(CPoint point, const glm::vec3 &ref)
{
	CVirtualClothTryOnDoc* doc = GetActiveDocument();//����doc�����˻�����Ҫ�������ļ�	 
	assert(doc);
	DataCamera3D* camera = doc->m_pCamera3D;


	glm::mat4 wp, iwp;
	iwp = wp = camera->m_ModelMatrix*camera->m_ViewMatrix;

	iwp = glm::affineInverse(iwp);
	glm::vec4 v4d(ref.x, ref.y, ref.z, 1.0f);
	v4d = v4d * wp;

	v4d.x = (point.x - (float)camera->m_fWidth / 2.f)*v4d.w / ((float)camera->m_fWidth / 2.f);//modified by  2008.6.23,for bug2106
	v4d.y = (-point.y + (float)camera->m_fHeight / 2.f)*v4d.w / ((float)camera->m_fHeight / 2.f);

	v4d = v4d * iwp;

	return glm::vec3(v4d.x, v4d.y, v4d.z);
}
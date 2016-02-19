#pragma once


//View3D ��ͼ
#include "OpenGLView.h"
#include "ClothRender.h"

class View3D : public OpenGLView
{
	DECLARE_DYNCREATE(View3D)

public:
	View3D();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~View3D();

public:
	virtual void OnDraw(CDC* pDC);      // ��д�Ի��Ƹ���ͼ
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
protected:
	afx_msg void OnSize(UINT nType, int cx, int cy);//��ʱע�͵�
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);

	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMButtonUp(UINT nFlags, CPoint point);

	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnTimer(UINT_PTR nIDEvent);


private:
	ClothRender m_Render;//���ڹ���ʵ�ʵĻ��Ʋ���
};
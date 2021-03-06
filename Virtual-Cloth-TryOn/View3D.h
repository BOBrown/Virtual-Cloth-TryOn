#pragma once


//View3D 视图
#include "OpenGLView.h"
#include "ClothRender.h"


enum OperationView
{
	OPERATIONVIEW_NONE,
	OPERATIONVIEW_ROTATE,
	OPERATIONVIEW_TRANSLATE,
};

class View3D : public OpenGLView
{
	DECLARE_DYNCREATE(View3D)

public:
	View3D();           // 动态创建所使用的受保护的构造函数
	virtual ~View3D();

public:
	virtual void OnDraw(CDC* pDC);      // 重写以绘制该视图
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
protected:
	afx_msg void OnSize(UINT nType, int cx, int cy);//暂时注释掉
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);

	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMButtonUp(UINT nFlags, CPoint point);

	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	void OnRButtonMouseMove(UINT nFlags, CPoint point);
	void OnLButtonMouseMove(UINT nFlags, CPoint point);


	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnTimer(UINT_PTR nIDEvent);


public:
	ClothRender m_Render;//用于管理实际的绘制操作
	OperationView m_iOperationView;//视角操作标识符
	glm::vec3 m_LastPt;

public:
	glm::vec3 Conv2Dto3D(CPoint point, const glm::vec3 &ref);



	/***********************************仅仅用于测试滑块的功能，将视角操作域滑块关联起来，以下********************************************/
	void ViewRotateX(float dx);
	void ViewRotateY(float dy);
	void ViewScale(float delta);
	/***********************************仅仅用于测试滑块的功能，将视角操作域滑块关联起来，以上********************************************/
};
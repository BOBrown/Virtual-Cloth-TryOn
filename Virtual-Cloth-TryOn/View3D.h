#pragma once


//View3D 视图

class View3D : public CView
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
};
#pragma once


//View3D ��ͼ

class View3D : public CView
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
};
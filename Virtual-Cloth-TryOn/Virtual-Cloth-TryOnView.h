
// Virtual-Cloth-TryOnView.h : CVirtualClothTryOnView ��Ľӿ�
//

#pragma once


class CVirtualClothTryOnView : public CView
{
protected: // �������л�����
	CVirtualClothTryOnView();
	DECLARE_DYNCREATE(CVirtualClothTryOnView)

// ����
public:
	CVirtualClothTryOnDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CVirtualClothTryOnView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Virtual-Cloth-TryOnView.cpp �еĵ��԰汾
inline CVirtualClothTryOnDoc* CVirtualClothTryOnView::GetDocument() const
   { return reinterpret_cast<CVirtualClothTryOnDoc*>(m_pDocument); }
#endif



// Virtual-Cloth-TryOnView.h : CVirtualClothTryOnView 类的接口
//

#pragma once


class CVirtualClothTryOnView : public CView
{
protected: // 仅从序列化创建
	CVirtualClothTryOnView();
	DECLARE_DYNCREATE(CVirtualClothTryOnView)

// 特性
public:
	CVirtualClothTryOnDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CVirtualClothTryOnView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Virtual-Cloth-TryOnView.cpp 中的调试版本
inline CVirtualClothTryOnDoc* CVirtualClothTryOnView::GetDocument() const
   { return reinterpret_cast<CVirtualClothTryOnDoc*>(m_pDocument); }
#endif


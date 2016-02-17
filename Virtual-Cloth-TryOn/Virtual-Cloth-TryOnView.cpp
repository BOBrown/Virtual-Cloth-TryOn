
// Virtual-Cloth-TryOnView.cpp : CVirtualClothTryOnView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Virtual-Cloth-TryOn.h"
#endif

#include "Virtual-Cloth-TryOnDoc.h"
#include "Virtual-Cloth-TryOnView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CVirtualClothTryOnView

IMPLEMENT_DYNCREATE(CVirtualClothTryOnView, CView)

BEGIN_MESSAGE_MAP(CVirtualClothTryOnView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CVirtualClothTryOnView 构造/析构

CVirtualClothTryOnView::CVirtualClothTryOnView()
{
	// TODO:  在此处添加构造代码

}

CVirtualClothTryOnView::~CVirtualClothTryOnView()
{
}

BOOL CVirtualClothTryOnView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CVirtualClothTryOnView 绘制

void CVirtualClothTryOnView::OnDraw(CDC* /*pDC*/)
{
	CVirtualClothTryOnDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CVirtualClothTryOnView 打印

BOOL CVirtualClothTryOnView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CVirtualClothTryOnView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CVirtualClothTryOnView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CVirtualClothTryOnView 诊断

#ifdef _DEBUG
void CVirtualClothTryOnView::AssertValid() const
{
	CView::AssertValid();
}

void CVirtualClothTryOnView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CVirtualClothTryOnDoc* CVirtualClothTryOnView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CVirtualClothTryOnDoc)));
	return (CVirtualClothTryOnDoc*)m_pDocument;
}
#endif //_DEBUG


// CVirtualClothTryOnView 消息处理程序

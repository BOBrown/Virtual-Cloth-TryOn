
// Virtual-Cloth-TryOnView.cpp : CVirtualClothTryOnView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CVirtualClothTryOnView ����/����

CVirtualClothTryOnView::CVirtualClothTryOnView()
{
	// TODO:  �ڴ˴���ӹ������

}

CVirtualClothTryOnView::~CVirtualClothTryOnView()
{
}

BOOL CVirtualClothTryOnView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CVirtualClothTryOnView ����

void CVirtualClothTryOnView::OnDraw(CDC* /*pDC*/)
{
	CVirtualClothTryOnDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CVirtualClothTryOnView ��ӡ

BOOL CVirtualClothTryOnView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CVirtualClothTryOnView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CVirtualClothTryOnView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CVirtualClothTryOnView ���

#ifdef _DEBUG
void CVirtualClothTryOnView::AssertValid() const
{
	CView::AssertValid();
}

void CVirtualClothTryOnView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CVirtualClothTryOnDoc* CVirtualClothTryOnView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CVirtualClothTryOnDoc)));
	return (CVirtualClothTryOnDoc*)m_pDocument;
}
#endif //_DEBUG


// CVirtualClothTryOnView ��Ϣ�������

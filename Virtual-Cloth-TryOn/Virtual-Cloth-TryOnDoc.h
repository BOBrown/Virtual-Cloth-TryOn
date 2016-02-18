
// Virtual-Cloth-TryOnDoc.h : CVirtualClothTryOnDoc ��Ľӿ�
//


#pragma once
#include <vector>

class DataCloth;
class DataCamera3D;


class CVirtualClothTryOnDoc : public CDocument
{
protected: // �������л�����
	CVirtualClothTryOnDoc();
	DECLARE_DYNCREATE(CVirtualClothTryOnDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CVirtualClothTryOnDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	DataCloth*				m_pCloth;
	DataCamera3D*			m_pCamera3D;

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};

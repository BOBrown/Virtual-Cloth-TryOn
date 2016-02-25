#pragma once
#include "afxcmn.h"
#include "UpperCloth.h"
#include "UnderCloth.h"


// ClothFileOpen �Ի���

class ClothFileOpen : public CDialogEx
{
	DECLARE_DYNAMIC(ClothFileOpen)

public:
	ClothFileOpen(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ClothFileOpen();

// �Ի�������
	enum { IDD = IDD_CLOTH_FILE_OPEN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_ClothFileOpenTab;
	UpperCloth m_UpperClothDlg;
	UnderCloth m_UnderClothDlg;

	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};

#pragma once
#include "afxcmn.h"
#include "UpperCloth.h"
#include "UnderCloth.h"


// ClothFileOpen 对话框

class ClothFileOpen : public CDialogEx
{
	DECLARE_DYNAMIC(ClothFileOpen)

public:
	ClothFileOpen(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ClothFileOpen();

// 对话框数据
	enum { IDD = IDD_CLOTH_FILE_OPEN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_ClothFileOpenTab;
	UpperCloth m_UpperClothDlg;
	UnderCloth m_UnderClothDlg;

	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};

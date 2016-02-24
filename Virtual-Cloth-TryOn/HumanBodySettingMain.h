#pragma once
#include "afxcmn.h"


// HumanBodySettingMain �Ի���

class HumanBodySettingMain : public CDialogEx
{
	DECLARE_DYNAMIC(HumanBodySettingMain)

public:
	HumanBodySettingMain(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~HumanBodySettingMain();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();


	CSliderCtrl m_cMainGender;
	CSliderCtrl m_cMainFace;
	CSliderCtrl m_cMainTorso;
	bool m_bMainGender;
	bool m_bMainFace;
	bool m_bMainTorso;
	afx_msg void OnNMCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider3(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};

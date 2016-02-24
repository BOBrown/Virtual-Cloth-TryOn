// HumanBodySettingMain.cpp : 实现文件
//

#include "stdafx.h"
#include "Virtual-Cloth-TryOn.h"
#include "HumanBodySettingMain.h"
#include "afxdialogex.h"


// HumanBodySettingMain 对话框

IMPLEMENT_DYNAMIC(HumanBodySettingMain, CDialogEx)

HumanBodySettingMain::HumanBodySettingMain(CWnd* pParent /*=NULL*/)
	: CDialogEx(HumanBodySettingMain::IDD, pParent)
{

}

HumanBodySettingMain::~HumanBodySettingMain()
{
}

void HumanBodySettingMain::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, m_cMainGender);
	DDX_Control(pDX, IDC_SLIDER2, m_cMainFace);
	DDX_Control(pDX, IDC_SLIDER3, m_cMainTorso);
}


BEGIN_MESSAGE_MAP(HumanBodySettingMain, CDialogEx)
	ON_BN_CLICKED(IDOK, &HumanBodySettingMain::OnBnClickedOk)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER2, &HumanBodySettingMain::OnNMCustomdrawSlider2)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &HumanBodySettingMain::OnNMCustomdrawSlider1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER3, &HumanBodySettingMain::OnNMCustomdrawSlider3)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// HumanBodySettingMain 消息处理程序


void HumanBodySettingMain::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void HumanBodySettingMain::OnNMCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	m_bMainGender = false;
	m_bMainFace = false;
	m_bMainTorso = false;

	m_bMainFace = true;

	*pResult = 0;
}


void HumanBodySettingMain::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	m_bMainGender = false;
	m_bMainFace = false;
	m_bMainTorso = false;

	m_bMainGender = true;

	*pResult = 0;
}


void HumanBodySettingMain::OnNMCustomdrawSlider3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	m_bMainGender = false;
	m_bMainFace = false;
	m_bMainTorso = false;

	m_bMainTorso = true;


	*pResult = 0;
}


BOOL HumanBodySettingMain::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_bMainGender = false;
	m_bMainFace = false;
	m_bMainTorso = false;

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void HumanBodySettingMain::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (m_bMainGender)
	{
		CSliderCtrl   *pSlidCtrl0 = (CSliderCtrl*)GetDlgItem(IDC_SLIDER1);
		int a = m_cMainGender.GetPos();//取得当前位置值 
	}
	if (m_bMainFace)
	{
		CSliderCtrl   *pSlidCtrl1 = (CSliderCtrl*)GetDlgItem(IDC_SLIDER2);
		int b = m_cMainFace.GetPos();//取得当前位置值 
	}
	if (m_bMainTorso)
	{
		CSliderCtrl   *pSlidCtrl2 = (CSliderCtrl*)GetDlgItem(IDC_SLIDER3);
		int c = m_cMainTorso.GetPos();//取得当前位置值
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

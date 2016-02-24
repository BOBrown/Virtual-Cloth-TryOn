// HumanBodySettingMain.cpp : 实现文件
//

#include "stdafx.h"
#include "Virtual-Cloth-TryOn.h"
#include "HumanBodySettingMain.h"
#include "afxdialogex.h"
#include "View3D.h"


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

	m_cMainGender.SetRange(0, 100); //设置滑块位置的最大值和最小值
	m_cMainGender.SetPos(50); //设置滑块的默认当前位置
	m_cMainGender.SetTicFreq(1);//每10个单位画一刻度

	m_cMainFace.SetRange(0, 100); //设置滑块位置的最大值和最小值
	m_cMainFace.SetPos(50);//设置滑块的默认当前位置
	m_cMainFace.SetTicFreq(1);//每10个单位画一刻度

	m_cMainTorso.SetRange(0, 100); //设置滑块位置的最大值和最小值
	m_cMainTorso.SetPos(50);        
	m_cMainTorso.SetTicFreq(1);//每10个单位画一刻度

	m_iMainGender = 50;
	m_iMainFace = 50;
	m_iMainTorso = 50;

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void HumanBodySettingMain::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (m_bMainGender)
	{
		CSliderCtrl   *pSlidCtrl0 = (CSliderCtrl*)GetDlgItem(IDC_SLIDER1);
		int dx = m_cMainGender.GetPos();//取得当前位置值
		m_p3DView->ViewRotateX((dx - m_iMainGender)*10);
		m_iMainGender = dx;

		//重绘opengl中场景
		m_p3DView->SceneBegin();
		m_p3DView->m_Render.Render();
		m_p3DView->SceneFlip();
		m_p3DView->SceneEnd();
	}
	if (m_bMainFace)
	{
		CSliderCtrl   *pSlidCtrl1 = (CSliderCtrl*)GetDlgItem(IDC_SLIDER2);
		int dx = m_cMainFace.GetPos();//取得当前位置值 
	}
	if (m_bMainTorso)
	{
		CSliderCtrl   *pSlidCtrl2 = (CSliderCtrl*)GetDlgItem(IDC_SLIDER3);
		int c = m_cMainTorso.GetPos();//取得当前位置值
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

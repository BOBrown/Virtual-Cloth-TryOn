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
	, m_fHuamnBodyHeight(0)
	, m_fHumanBodyHeightMax(0)
	, m_fHumanBodyHeightMin(0)
{
}

HumanBodySettingMain::~HumanBodySettingMain()
{
}

void HumanBodySettingMain::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, m_cMainHeight);
	DDX_Control(pDX, IDC_SLIDER2, m_cMainShoulderLength);
	DDX_Control(pDX, IDC_SLIDER3, m_cMainBust);
	DDX_Text(pDX, IDC_EDIT1, m_fHuamnBodyHeight);
	DDX_Text(pDX, IDC_EDIT8, m_fHumanBodyHeightMax);
	DDX_Text(pDX, IDC_EDIT9, m_fHumanBodyHeightMin);
}


BEGIN_MESSAGE_MAP(HumanBodySettingMain, CDialogEx)
	ON_BN_CLICKED(IDOK, &HumanBodySettingMain::OnBnClickedOk)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER2, &HumanBodySettingMain::OnNMCustomdrawSlider2)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &HumanBodySettingMain::OnNMCustomdrawSlider1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER3, &HumanBodySettingMain::OnNMCustomdrawSlider3)
	ON_WM_HSCROLL()
	ON_EN_CHANGE(IDC_EDIT1, &HumanBodySettingMain::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT8, &HumanBodySettingMain::OnEnChangeEdit8)
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
	m_bMainHeight = false;
	m_bMainShoulderLength = false;
	m_bMainBust = false;
	m_bMainShoulderLength = true;

	*pResult = 0;
}


void HumanBodySettingMain::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	m_bMainHeight = false;
	m_bMainShoulderLength = false;
	m_bMainBust = false;
	m_bMainHeight = true;

	*pResult = 0;
}


void HumanBodySettingMain::OnNMCustomdrawSlider3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	m_bMainHeight = false;
	m_bMainShoulderLength = false;
	m_bMainBust = false;
	m_bMainBust = true;

	*pResult = 0;
}


BOOL HumanBodySettingMain::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_bMainHeight = false;
	m_bMainShoulderLength = false;
	m_bMainBust = false;

	m_cMainHeight.SetRange(0, 100); //设置滑块位置的最大值和最小值
	m_cMainHeight.SetPos(50); //设置滑块的默认当前位置
	m_cMainHeight.SetTicFreq(1);//每10个单位画一刻度

	m_cMainShoulderLength.SetRange(0, 100); //设置滑块位置的最大值和最小值
	m_cMainShoulderLength.SetPos(50);//设置滑块的默认当前位置
	m_cMainShoulderLength.SetTicFreq(1);//每10个单位画一刻度

	m_cMainBust.SetRange(0, 100); //设置滑块位置的最大值和最小值
	m_cMainBust.SetPos(50);        
	m_cMainBust.SetTicFreq(1);//每10个单位画一刻度

	m_iMainHeight = 50;
	m_iMainShoulderLength = 50;
	m_iMainBust = 50;

	//设置edit control中的初始值与slider control中一致
	m_fHuamnBodyHeight = m_iMainHeight;








	//每一个滑块的极大值和极小值可基于导入的人体模型参数进行刷新
	m_fHumanBodyHeightMax = 0;
	m_fHumanBodyHeightMin = 100;


	UpdateData(false);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void HumanBodySettingMain::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (m_bMainHeight)
	{
		CSliderCtrl   *pSlidCtrl0 = (CSliderCtrl*)GetDlgItem(IDC_SLIDER1);
		int dx = m_cMainHeight.GetPos();//取得当前位置值
		m_p3DView->ViewRotateX((dx - m_iMainHeight)*10);
		m_iMainHeight = dx;

		//实时刷新edit control中的值
		m_fHuamnBodyHeight = dx;

		//重绘opengl中场景
		m_p3DView->SceneBegin();
		m_p3DView->m_Render.Render();
		m_p3DView->SceneFlip();
		m_p3DView->SceneEnd();
	}
	if (m_bMainShoulderLength)
	{
		CSliderCtrl   *pSlidCtrl1 = (CSliderCtrl*)GetDlgItem(IDC_SLIDER2);
		int dx = m_cMainShoulderLength.GetPos();//取得当前位置值 
	}
	if (m_bMainBust)
	{
		CSliderCtrl   *pSlidCtrl2 = (CSliderCtrl*)GetDlgItem(IDC_SLIDER3);
		int c = m_cMainBust.GetPos();//取得当前位置值
	}


	UpdateData(false);

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void HumanBodySettingMain::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	m_cMainHeight.SetPos(m_fHuamnBodyHeight); //设置滑块的默认当前位置
}


void HumanBodySettingMain::OnEnChangeEdit8()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

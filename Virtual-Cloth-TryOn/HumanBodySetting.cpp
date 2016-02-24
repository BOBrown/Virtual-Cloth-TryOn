// HumanBodySetting.cpp : 实现文件
//

#include "stdafx.h"
#include "Virtual-Cloth-TryOn.h"
#include "HumanBodySetting.h"
#include "afxdialogex.h"


// HumanBodySetting 对话框

IMPLEMENT_DYNAMIC(HumanBodySetting, CDialogEx)

HumanBodySetting::HumanBodySetting(CWnd* pParent /*=NULL*/)
	: CDialogEx(HumanBodySetting::IDD, pParent)
{
}

HumanBodySetting::~HumanBodySetting()
{
}

void HumanBodySetting::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_HUMAN_BODY_TAB, m_HumanBodyTab);
}


BEGIN_MESSAGE_MAP(HumanBodySetting, CDialogEx)
	ON_BN_CLICKED(IDOK, &HumanBodySetting::OnBnClickedOk)
	ON_NOTIFY(TCN_SELCHANGE, IDC_HUMAN_BODY_TAB, &HumanBodySetting::OnTcnSelchangeHumanBodyTab)
END_MESSAGE_MAP()


// HumanBodySetting 消息处理程序


void HumanBodySetting::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void HumanBodySetting::OnTcnSelchangeHumanBodyTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  在此添加控件通知处理程序代码
	int CurSel = m_HumanBodyTab.GetCurSel();

	switch (CurSel)
	{
	case 0:
		m_HumanBodySettingMain.ShowWindow(true);
		m_HumanBodySettingGender.ShowWindow(false);
		break;
	case 1:
		m_HumanBodySettingMain.ShowWindow(false);
		m_HumanBodySettingGender.ShowWindow(true);
		break;
	}

	*pResult = 0;
}


BOOL HumanBodySetting::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_HumanBodyTab.InsertItem(0, _T("Main"));
	m_HumanBodyTab.InsertItem(1, _T("Gender"));
	m_HumanBodyTab.InsertItem(2, _T("Face"));
	m_HumanBodyTab.InsertItem(3, _T("Torso"));



	//设置IDC_TAB1为父窗口
	m_HumanBodySettingMain.Create(IDD_DIALOG1, GetDlgItem(IDC_HUMAN_BODY_TAB));
	m_HumanBodySettingGender.Create(IDD_DIALOG2, GetDlgItem(IDC_HUMAN_BODY_TAB));

	//获得IDC_TABTEST客户区大小
	CRect rc;
	m_HumanBodyTab.GetClientRect(&rc);

	//调整子对话框在父窗口中的位置
	rc.top += 30;
	rc.bottom -= 8;
	rc.left += 8;
	rc.right -= 8;

	//设置子对话框尺寸并移动到指定位置
	m_HumanBodySettingMain.MoveWindow(&rc);
	m_HumanBodySettingGender.MoveWindow(&rc);

	//分别设置隐藏和显示
	m_HumanBodySettingMain.ShowWindow(true);
	m_HumanBodySettingGender.ShowWindow(false);

	//设置默认的选项卡
	m_HumanBodyTab.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}

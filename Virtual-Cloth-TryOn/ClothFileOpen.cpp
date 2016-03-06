// ClothFileOpen.cpp : 实现文件
//

#include "stdafx.h"
#include "Virtual-Cloth-TryOn.h"
#include "ClothFileOpen.h"
#include "afxdialogex.h"


// ClothFileOpen 对话框
//xuhaocan_test addb by xuhaocan  2016.3.6
IMPLEMENT_DYNAMIC(ClothFileOpen, CDialogEx)

ClothFileOpen::ClothFileOpen(CWnd* pParent /*=NULL*/)
	: CDialogEx(ClothFileOpen::IDD, pParent)
{

}

ClothFileOpen::~ClothFileOpen()
{
}

void ClothFileOpen::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CLOTH_FILE_OPEN_TAB, m_ClothFileOpenTab);
}


BEGIN_MESSAGE_MAP(ClothFileOpen, CDialogEx)
	ON_BN_CLICKED(IDOK, &ClothFileOpen::OnBnClickedOk)
	ON_NOTIFY(TCN_SELCHANGE, IDC_CLOTH_FILE_OPEN_TAB, &ClothFileOpen::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// ClothFileOpen 消息处理程序


void ClothFileOpen::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


BOOL ClothFileOpen::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_ClothFileOpenTab.InsertItem(0, _T("UpperCloth"));
	m_ClothFileOpenTab.InsertItem(1, _T("UnderCloth"));
	m_ClothFileOpenTab.InsertItem(2, _T("Skirt"));

	CFont m_NewFont;
	m_NewFont.CreateFont(50, 20, 0, 0, 900, TRUE, 0, 0, 1, 0, 0, 0, 0, _T("Arial"));
	m_ClothFileOpenTab.SetFont(&m_NewFont);


	//设置IDC_TAB1为父窗口
	m_UpperClothDlg.Create(IDD_DIALOG3, GetDlgItem(IDC_CLOTH_FILE_OPEN_TAB));
	m_UnderClothDlg.Create(IDD_DIALOG4, GetDlgItem(IDC_CLOTH_FILE_OPEN_TAB));

	//获得IDC_TABTEST客户区大小
	CRect rc;
	m_ClothFileOpenTab.GetClientRect(&rc);

	//调整子对话框在父窗口中的位置
	//rc.top += 30;
	//rc.bottom -= 8;
	//rc.left += 8;
	//rc.right -= 8;


	rc.top += 30;
	rc.bottom -= 0;
	rc.left += 0;
	rc.right -= 0;

	//设置子对话框尺寸并移动到指定位置
	m_UpperClothDlg.MoveWindow(&rc);
	m_UnderClothDlg.MoveWindow(&rc);

	//分别设置隐藏和显示
	m_UpperClothDlg.ShowWindow(true);
	m_UnderClothDlg.ShowWindow(false);

	//设置默认的选项卡
	m_ClothFileOpenTab.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void ClothFileOpen::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  在此添加控件通知处理程序代码
	int CurSel = m_ClothFileOpenTab.GetCurSel();

	switch (CurSel)
	{
	case 0:
		m_UpperClothDlg.ShowWindow(true);
		m_UnderClothDlg.ShowWindow(false);
		break;
	case 1:
		m_UpperClothDlg.ShowWindow(false);
		m_UnderClothDlg.ShowWindow(true);
		break;
	}

	*pResult = 0;
}

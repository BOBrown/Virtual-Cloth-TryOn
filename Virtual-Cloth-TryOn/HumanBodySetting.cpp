// HumanBodySetting.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Virtual-Cloth-TryOn.h"
#include "HumanBodySetting.h"
#include "afxdialogex.h"


// HumanBodySetting �Ի���

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
	DDX_Control(pDX, IDC_HUMAN_BODY_TAB, m_HuamnBodyTab);

	m_HuamnBodyTab.InsertItem(0, _T("Main"));
	m_HuamnBodyTab.InsertItem(1, _T("Gender"));
	m_HuamnBodyTab.InsertItem(2, _T("Face"));
	m_HuamnBodyTab.InsertItem(3, _T("Torso"));
}


BEGIN_MESSAGE_MAP(HumanBodySetting, CDialogEx)
	ON_BN_CLICKED(IDOK, &HumanBodySetting::OnBnClickedOk)
END_MESSAGE_MAP()


// HumanBodySetting ��Ϣ�������


void HumanBodySetting::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}

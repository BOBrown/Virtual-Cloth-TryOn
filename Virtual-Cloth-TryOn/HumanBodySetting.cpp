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
}


BEGIN_MESSAGE_MAP(HumanBodySetting, CDialogEx)
	ON_BN_CLICKED(IDOK, &HumanBodySetting::OnBnClickedOk)
	ON_NOTIFY(TCN_SELCHANGE, IDC_HUMAN_BODY_TAB, &HumanBodySetting::OnTcnSelchangeHumanBodyTab)
END_MESSAGE_MAP()


// HumanBodySetting ��Ϣ�������


void HumanBodySetting::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void HumanBodySetting::OnTcnSelchangeHumanBodyTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	int CurSel = m_HuamnBodyTab.GetCurSel();

	switch (CurSel)
	{
	case 0:
		m_HuamnBodySettingMain.ShowWindow(true);
		m_HuamnBodySettingGender.ShowWindow(false);
		break;
	case 1:
		m_HuamnBodySettingMain.ShowWindow(false);
		m_HuamnBodySettingGender.ShowWindow(true);
		break;
	}

	*pResult = 0;
}


BOOL HumanBodySetting::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_HuamnBodyTab.InsertItem(0, _T("Main"));
	m_HuamnBodyTab.InsertItem(1, _T("Gender"));
	m_HuamnBodyTab.InsertItem(2, _T("Face"));
	m_HuamnBodyTab.InsertItem(3, _T("Torso"));



	//����IDC_TAB1Ϊ������
	m_HuamnBodySettingMain.Create(IDD_DIALOG1, GetDlgItem(IDC_HUMAN_BODY_TAB));
	m_HuamnBodySettingGender.Create(IDD_DIALOG2, GetDlgItem(IDC_HUMAN_BODY_TAB));

	//���IDC_TABTEST�ͻ�����С
	CRect rc;
	m_HuamnBodyTab.GetClientRect(&rc);

	//�����ӶԻ����ڸ������е�λ��
	rc.top += 30;
	rc.bottom -= 8;
	rc.left += 8;
	rc.right -= 8;

	//�����ӶԻ���ߴ粢�ƶ���ָ��λ��
	m_HuamnBodySettingMain.MoveWindow(&rc);
	m_HuamnBodySettingGender.MoveWindow(&rc);

	//�ֱ��������غ���ʾ
	m_HuamnBodySettingMain.ShowWindow(true);
	m_HuamnBodySettingGender.ShowWindow(false);

	//����Ĭ�ϵ�ѡ�
	m_HuamnBodyTab.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}

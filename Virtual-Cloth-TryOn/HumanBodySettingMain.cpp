// HumanBodySettingMain.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Virtual-Cloth-TryOn.h"
#include "HumanBodySettingMain.h"
#include "afxdialogex.h"
#include "View3D.h"


// HumanBodySettingMain �Ի���

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
	DDX_Control(pDX, IDC_SLIDER1, m_cMainHeight);
	DDX_Control(pDX, IDC_SLIDER2, m_cMainShoulderLength);
	DDX_Control(pDX, IDC_SLIDER3, m_cMainBust);
}


BEGIN_MESSAGE_MAP(HumanBodySettingMain, CDialogEx)
	ON_BN_CLICKED(IDOK, &HumanBodySettingMain::OnBnClickedOk)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER2, &HumanBodySettingMain::OnNMCustomdrawSlider2)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &HumanBodySettingMain::OnNMCustomdrawSlider1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER3, &HumanBodySettingMain::OnNMCustomdrawSlider3)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// HumanBodySettingMain ��Ϣ�������


void HumanBodySettingMain::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void HumanBodySettingMain::OnNMCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_bMainHeight = false;
	m_bMainShoulderLength = false;
	m_bMainBust = false;
	m_bMainShoulderLength = true;

	*pResult = 0;
}


void HumanBodySettingMain::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_bMainHeight = false;
	m_bMainShoulderLength = false;
	m_bMainBust = false;
	m_bMainHeight = true;

	*pResult = 0;
}


void HumanBodySettingMain::OnNMCustomdrawSlider3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_bMainHeight = false;
	m_bMainShoulderLength = false;
	m_bMainBust = false;
	m_bMainBust = true;

	*pResult = 0;
}


BOOL HumanBodySettingMain::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_bMainHeight = false;
	m_bMainShoulderLength = false;
	m_bMainBust = false;

	m_cMainHeight.SetRange(0, 100); //���û���λ�õ����ֵ����Сֵ
	m_cMainHeight.SetPos(50); //���û����Ĭ�ϵ�ǰλ��
	m_cMainHeight.SetTicFreq(1);//ÿ10����λ��һ�̶�

	m_cMainShoulderLength.SetRange(0, 100); //���û���λ�õ����ֵ����Сֵ
	m_cMainShoulderLength.SetPos(50);//���û����Ĭ�ϵ�ǰλ��
	m_cMainShoulderLength.SetTicFreq(1);//ÿ10����λ��һ�̶�

	m_cMainBust.SetRange(0, 100); //���û���λ�õ����ֵ����Сֵ
	m_cMainBust.SetPos(50);        
	m_cMainBust.SetTicFreq(1);//ÿ10����λ��һ�̶�

	m_iMainHeight = 50;
	m_iMainShoulderLength = 50;
	m_iMainBust = 50;

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void HumanBodySettingMain::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (m_bMainHeight)
	{
		CSliderCtrl   *pSlidCtrl0 = (CSliderCtrl*)GetDlgItem(IDC_SLIDER1);
		int dx = m_cMainHeight.GetPos();//ȡ�õ�ǰλ��ֵ
		m_p3DView->ViewRotateX((dx - m_iMainHeight)*10);
		m_iMainHeight = dx;

		//�ػ�opengl�г���
		m_p3DView->SceneBegin();
		m_p3DView->m_Render.Render();
		m_p3DView->SceneFlip();
		m_p3DView->SceneEnd();
	}
	if (m_bMainShoulderLength)
	{
		CSliderCtrl   *pSlidCtrl1 = (CSliderCtrl*)GetDlgItem(IDC_SLIDER2);
		int dx = m_cMainShoulderLength.GetPos();//ȡ�õ�ǰλ��ֵ 
	}
	if (m_bMainBust)
	{
		CSliderCtrl   *pSlidCtrl2 = (CSliderCtrl*)GetDlgItem(IDC_SLIDER3);
		int c = m_cMainBust.GetPos();//ȡ�õ�ǰλ��ֵ
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

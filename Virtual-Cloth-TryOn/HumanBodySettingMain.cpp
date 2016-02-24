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
	m_bMainGender = false;
	m_bMainFace = false;
	m_bMainTorso = false;
	m_bMainFace = true;

	*pResult = 0;
}


void HumanBodySettingMain::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_bMainGender = false;
	m_bMainFace = false;
	m_bMainTorso = false;
	m_bMainGender = true;

	*pResult = 0;
}


void HumanBodySettingMain::OnNMCustomdrawSlider3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_bMainGender = false;
	m_bMainFace = false;
	m_bMainTorso = false;
	m_bMainTorso = true;

	*pResult = 0;
}


BOOL HumanBodySettingMain::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_bMainGender = false;
	m_bMainFace = false;
	m_bMainTorso = false;

	m_cMainGender.SetRange(0, 100); //���û���λ�õ����ֵ����Сֵ
	m_cMainGender.SetPos(50); //���û����Ĭ�ϵ�ǰλ��
	m_cMainGender.SetTicFreq(1);//ÿ10����λ��һ�̶�

	m_cMainFace.SetRange(0, 100); //���û���λ�õ����ֵ����Сֵ
	m_cMainFace.SetPos(50);//���û����Ĭ�ϵ�ǰλ��
	m_cMainFace.SetTicFreq(1);//ÿ10����λ��һ�̶�

	m_cMainTorso.SetRange(0, 100); //���û���λ�õ����ֵ����Сֵ
	m_cMainTorso.SetPos(50);        
	m_cMainTorso.SetTicFreq(1);//ÿ10����λ��һ�̶�

	m_iMainGender = 50;
	m_iMainFace = 50;
	m_iMainTorso = 50;

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void HumanBodySettingMain::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (m_bMainGender)
	{
		CSliderCtrl   *pSlidCtrl0 = (CSliderCtrl*)GetDlgItem(IDC_SLIDER1);
		int dx = m_cMainGender.GetPos();//ȡ�õ�ǰλ��ֵ
		m_p3DView->ViewRotateX((dx - m_iMainGender)*10);
		m_iMainGender = dx;

		//�ػ�opengl�г���
		m_p3DView->SceneBegin();
		m_p3DView->m_Render.Render();
		m_p3DView->SceneFlip();
		m_p3DView->SceneEnd();
	}
	if (m_bMainFace)
	{
		CSliderCtrl   *pSlidCtrl1 = (CSliderCtrl*)GetDlgItem(IDC_SLIDER2);
		int dx = m_cMainFace.GetPos();//ȡ�õ�ǰλ��ֵ 
	}
	if (m_bMainTorso)
	{
		CSliderCtrl   *pSlidCtrl2 = (CSliderCtrl*)GetDlgItem(IDC_SLIDER3);
		int c = m_cMainTorso.GetPos();//ȡ�õ�ǰλ��ֵ
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

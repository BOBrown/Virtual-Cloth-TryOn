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
}


BEGIN_MESSAGE_MAP(HumanBodySetting, CDialogEx)
END_MESSAGE_MAP()


// HumanBodySetting ��Ϣ�������

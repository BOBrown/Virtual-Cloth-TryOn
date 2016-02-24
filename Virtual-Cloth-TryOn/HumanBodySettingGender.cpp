// HumanBodySettingGender.cpp : 实现文件
//

#include "stdafx.h"
#include "Virtual-Cloth-TryOn.h"
#include "HumanBodySettingGender.h"
#include "afxdialogex.h"


// HumanBodySettingGender 对话框

IMPLEMENT_DYNAMIC(HumanBodySettingGender, CDialogEx)

HumanBodySettingGender::HumanBodySettingGender(CWnd* pParent /*=NULL*/)
	: CDialogEx(HumanBodySettingGender::IDD, pParent)
{

}

HumanBodySettingGender::~HumanBodySettingGender()
{
}

void HumanBodySettingGender::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(HumanBodySettingGender, CDialogEx)
END_MESSAGE_MAP()


// HumanBodySettingGender 消息处理程序

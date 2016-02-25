// UpperCloth.cpp : 实现文件
//

#include "stdafx.h"
#include "Virtual-Cloth-TryOn.h"
#include "UpperCloth.h"
#include "afxdialogex.h"


// UpperCloth 对话框

IMPLEMENT_DYNAMIC(UpperCloth, CDialogEx)

UpperCloth::UpperCloth(CWnd* pParent /*=NULL*/)
	: CDialogEx(UpperCloth::IDD, pParent)
{

}

UpperCloth::~UpperCloth()
{
}

void UpperCloth::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(UpperCloth, CDialogEx)
END_MESSAGE_MAP()


// UpperCloth 消息处理程序

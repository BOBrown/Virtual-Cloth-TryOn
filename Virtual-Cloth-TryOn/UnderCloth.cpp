// UnderCloth.cpp : 实现文件
//

#include "stdafx.h"
#include "Virtual-Cloth-TryOn.h"
#include "UnderCloth.h"
#include "afxdialogex.h"


// UnderCloth 对话框

IMPLEMENT_DYNAMIC(UnderCloth, CDialogEx)

UnderCloth::UnderCloth(CWnd* pParent /*=NULL*/)
	: CDialogEx(UnderCloth::IDD, pParent)
{

}

UnderCloth::~UnderCloth()
{
}

void UnderCloth::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(UnderCloth, CDialogEx)
END_MESSAGE_MAP()


// UnderCloth 消息处理程序

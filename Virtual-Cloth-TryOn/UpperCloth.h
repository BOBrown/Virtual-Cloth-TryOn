#pragma once


// UpperCloth 对话框

class UpperCloth : public CDialogEx
{
	DECLARE_DYNAMIC(UpperCloth)

public:
	UpperCloth(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~UpperCloth();

// 对话框数据
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};

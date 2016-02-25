#pragma once


// UnderCloth 对话框

class UnderCloth : public CDialogEx
{
	DECLARE_DYNAMIC(UnderCloth)

public:
	UnderCloth(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~UnderCloth();

// 对话框数据
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};

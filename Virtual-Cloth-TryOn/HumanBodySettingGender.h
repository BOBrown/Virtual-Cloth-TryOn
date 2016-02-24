#pragma once


// HumanBodySettingGender 对话框

class HumanBodySettingGender : public CDialogEx
{
	DECLARE_DYNAMIC(HumanBodySettingGender)

public:
	HumanBodySettingGender(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~HumanBodySettingGender();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};

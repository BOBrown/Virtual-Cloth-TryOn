#pragma once


// HumanBodySettingGender �Ի���

class HumanBodySettingGender : public CDialogEx
{
	DECLARE_DYNAMIC(HumanBodySettingGender)

public:
	HumanBodySettingGender(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~HumanBodySettingGender();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};

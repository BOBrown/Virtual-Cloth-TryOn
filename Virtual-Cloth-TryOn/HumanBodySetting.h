#pragma once


// HumanBodySetting �Ի���

class HumanBodySetting : public CDialogEx
{
	DECLARE_DYNAMIC(HumanBodySetting)

public:
	HumanBodySetting(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~HumanBodySetting();

// �Ի�������
	enum { IDD = IDD_HUMAN_BODY_SETTING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};

#pragma once


// UpperCloth �Ի���

class UpperCloth : public CDialogEx
{
	DECLARE_DYNAMIC(UpperCloth)

public:
	UpperCloth(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~UpperCloth();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};

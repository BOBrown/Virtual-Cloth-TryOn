#pragma once


// UnderCloth �Ի���

class UnderCloth : public CDialogEx
{
	DECLARE_DYNAMIC(UnderCloth)

public:
	UnderCloth(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~UnderCloth();

// �Ի�������
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};

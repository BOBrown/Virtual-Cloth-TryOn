
// MainFrm.h : CMainFrame ��Ľӿ�
//

#pragma once

class HumanBodySetting;
class ClothFileOpen;
class View3D;

class CMainFrame : public CFrameWnd
{
	
protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

private:
	View3D*		m_p3DView;
	HumanBodySetting* m_pHumanBodySettingDlg;
	ClothFileOpen* m_pClothFileOpenDlg;

public:
	BOOL CreateViews();
	afx_msg void OnMenuHumanBodySetting();
	afx_msg void OnClothFileOpen();
};



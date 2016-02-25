
// MainFrm.h : CMainFrame 类的接口
//

#pragma once

class HumanBodySetting;
class ClothFileOpen;
class View3D;

class CMainFrame : public CFrameWnd
{
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;

// 生成的消息映射函数
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



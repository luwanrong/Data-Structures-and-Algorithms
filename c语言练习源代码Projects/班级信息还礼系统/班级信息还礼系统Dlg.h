// 班级信息还礼系统Dlg.h : header file
//

#if !defined(AFX_DLG_H__242F0626_0D86_49BB_BA23_1497DE3C8477__INCLUDED_)
#define AFX_DLG_H__242F0626_0D86_49BB_BA23_1497DE3C8477__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

class CMyDlg : public CDialog
{
// Construction
public:
	CMyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyDlg)
	enum { IDD = IDD_MY_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonTc();
	afx_msg void OnButtonTj();
	afx_msg void OnButtonXg();
	afx_msg void OnButtonQd();
	afx_msg void OnButtonQx();
	afx_msg void OnButtonSyg();
	afx_msg void OnButtonXyg();
	afx_msg void OnButtonDyg();
	afx_msg void OnButtonMyg();
	afx_msg void OnButtonSc();
	afx_msg void OnAppExit();
	afx_msg void OnFileSave();
	afx_msg void OnFileOpen();
	afx_msg void OnAppAbout();
	afx_msg void OnButtonCx();
	afx_msg void OnKillfocusEditXh();
	afx_msg void OnKillfocusEditXb();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__242F0626_0D86_49BB_BA23_1497DE3C8477__INCLUDED_)

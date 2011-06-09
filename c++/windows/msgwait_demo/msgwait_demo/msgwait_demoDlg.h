// msgwait_demoDlg.h : header file
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"

class ThreadData; 

// Cmsgwait_demoDlg dialog
class Cmsgwait_demoDlg : public CDialog
{
// Construction
public:
	Cmsgwait_demoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MSGWAIT_DEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CAnimateCtrl m_fileNukeAnimation;
	ThreadData* m_pThreadData;
public:
	afx_msg void OnBnClickedBtnStartThread();
	CStatic m_status;
};

// msgwait_demoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "msgwait_demo.h"
#include "msgwait_demoDlg.h"
#include "ThreadData.h" 
#include <math.h> 

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// Cmsgwait_demoDlg dialog




Cmsgwait_demoDlg::Cmsgwait_demoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(Cmsgwait_demoDlg::IDD, pParent), 
	m_pThreadData(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cmsgwait_demoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FILE_NUKE_ANIMATION, m_fileNukeAnimation);
	DDX_Control(pDX, IDC_STATUS, m_status);
}

BEGIN_MESSAGE_MAP(Cmsgwait_demoDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_START_THREAD, &Cmsgwait_demoDlg::OnBnClickedBtnStartThread)
END_MESSAGE_MAP()


// Cmsgwait_demoDlg message handlers

BOOL Cmsgwait_demoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	char dir[500]; 
	GetCurrentDirectory(500, dir); 
	CString fileNukePath(dir); 
	fileNukePath += "\\FILENUKE.AVI";
	m_fileNukeAnimation.Open(fileNukePath); 
	m_fileNukeAnimation.Play(0, -1, -1); 

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Cmsgwait_demoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Cmsgwait_demoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Cmsgwait_demoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

UINT MyThreadProc( LPVOID pParam )
{
    ThreadData* pObject = (ThreadData*)pParam;

    if (pObject == NULL ||
        !pObject->IsKindOf(RUNTIME_CLASS(ThreadData)))
    return 1;   

	// Do some processing.
	int x = 0; 
	while (x++ < 5000)
	{
		for (int i=0; i<50000; i++)
			double sum = sqrt((double)i+1) * sqrt((double)i+2); 
	}

    return 0;
}

void Cmsgwait_demoDlg::OnBnClickedBtnStartThread()
{
	m_pThreadData = new ThreadData;
	CWinThread* pWorkThread = AfxBeginThread(MyThreadProc, m_pThreadData);
	
	m_status.SetWindowText("Status: Waiting for thread to complete."); 

	HANDLE handles[] = { pWorkThread->m_hThread }; 
	DWORD ret = 0;
	MSG msg; 

	while (1)
	{
		switch (MsgWaitForMultipleObjects(1, handles, FALSE, INFINITE, QS_ALLINPUT)) 
		{
		case WAIT_OBJECT_0:
			{
				m_status.SetWindowText("Status: Thread completed."); 
				return; 
			}
			break; 
		case WAIT_OBJECT_0+1:
			{
				// we have a message - peek and dispatch it
				if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) 
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
			}
			break; 
		case WAIT_FAILED:
			{
				m_status.SetWindowText("Status: Wait failed"); 
				return; 
			}
			break; 
		}
	}
}


// MsgPumpThread.cpp : implementation file
//

#include "stdafx.h"
#include "winthread_demo.h"
#include "MsgPumpThread.h"
#include <iostream> 
#include "MyMessages.h" 

using std::cout; 

// CMsgPumpThread

IMPLEMENT_DYNCREATE(CMsgPumpThread, CWinThread)

CMsgPumpThread::CMsgPumpThread()
{
}

CMsgPumpThread::~CMsgPumpThread()
{
}

BOOL CMsgPumpThread::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	return TRUE;
}

int CMsgPumpThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CMsgPumpThread, CWinThread)
	ON_THREAD_MESSAGE(_USR_HELP, OnUsrHelp)
END_MESSAGE_MAP()

// CMsgPumpThread message handlers
void CMsgPumpThread::OnUsrHelp(WPARAM wParam, LPARAM lParam)
{
	cout << "Handling OnUsrHelp message.\n"; 
}

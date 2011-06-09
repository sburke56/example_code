// winthread_demo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "winthread_demo.h"
#include "MsgPumpThread.h" 
#include <iostream> 
#include "MyMessages.h" 

using std::cout; 

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		_tprintf(_T("Fatal Error: MFC initialization failed\n"));
		nRetCode = 1;
	}
	else
	{
		// TODO: code your application's behavior here.
		CMsgPumpThread* msgPumpThread = new CMsgPumpThread();
		msgPumpThread->CreateThread(CREATE_SUSPENDED);
		msgPumpThread->ResumeThread();

		Sleep(2000); 
		PostThreadMessage(msgPumpThread->m_nThreadID, _USR_HELP, 0, 0);
		Sleep(2000); 
		PostThreadMessage(msgPumpThread->m_nThreadID, WM_QUIT, 0, 0);
		
		WaitForSingleObject(msgPumpThread->m_hThread, INFINITE);
		cout << "Waiting for the thread to complete is finished, exiting.\n"; 
	}

	return nRetCode;
}

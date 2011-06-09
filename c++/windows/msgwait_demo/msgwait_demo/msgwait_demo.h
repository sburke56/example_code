// msgwait_demo.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Cmsgwait_demoApp:
// See msgwait_demo.cpp for the implementation of this class
//

class Cmsgwait_demoApp : public CWinApp
{
public:
	Cmsgwait_demoApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Cmsgwait_demoApp theApp;
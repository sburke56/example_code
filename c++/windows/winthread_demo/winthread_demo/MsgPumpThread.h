#pragma once



// CMsgPumpThread

class CMsgPumpThread : public CWinThread
{
	DECLARE_DYNCREATE(CMsgPumpThread)

protected:
	virtual ~CMsgPumpThread();

public:
	//TODO: research why this constructor is protected in the template
	CMsgPumpThread();           // protected constructor used by dynamic creation
	
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	void OnUsrHelp(WPARAM wParam, LPARAM lParam);

protected:
	DECLARE_MESSAGE_MAP()
};



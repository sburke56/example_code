#ifndef _PROCESS_THREAD_H
#define _PROCESS_THREAD_H

#include <qthread.h> 

class QDialog; 

class ProcessThread : public QThread
{
public:
    ProcessThread(QDialog* const pDlg);
    ~ProcessThread();

    void run(); 

private:
    ProcessThread(const ProcessThread&); 
    ProcessThread& operator=(const ProcessThread&); 

    QDialog* _pDlg; 
};
#endif




#include "processthread.hpp"
#include <qapplication.h> 
#include <cmath> 
#include "progressevents.hpp" 

using namespace std; 
using namespace events::progress;

ProcessThread::ProcessThread(QDialog* const pDlg) : 
    _pDlg(pDlg)
{
}

ProcessThread::~ProcessThread()
{
}

void ProcessThread::run()
{
    QApplication::sendEvent((QObject*)_pDlg, new NumOperations(300)); 
    
    int list[10000];
    for (int k = 0; k < 10000; k++)
        list[k] = k * 11;
    
    for (int i = 0; i<100; ++i)
    {
        for (int j = 0; j < 10000; j++)
            for (int i = 0; i < 10000; i++)
                if (list[i] == (2 + list[j]))
                    list[i]++;

        QApplication::sendEvent((QObject*)_pDlg, new Step()); 
    }

    QApplication::sendEvent((QObject*)_pDlg, new Completed()); 
}

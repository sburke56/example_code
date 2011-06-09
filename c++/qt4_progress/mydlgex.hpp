#ifndef _MY_DLG_EX_H
#define _MY_DLG_EX_H
 
#include "ui_mydlgex.h"

class ProcessThread; 

class MyDlgEx : public QDialog, private Ui::MyDlg
{
    Q_OBJECT
 
public:
    MyDlgEx(QWidget *parent = 0);
 
public slots:
    void btnTest_clicked(); 
    void btnShowProgress_clicked(); 

private: 
    void SetDlgFlags(); 
    void CenterDlg(); 
    void SetConnections();
    void customEvent(QEvent * e);
    
    size_t _steps; 
    ProcessThread* _pProc; 
};
 
#endif

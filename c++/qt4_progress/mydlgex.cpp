#include "mydlgex.hpp" 
#include <QtGui> 
#include <qevent.h> 

#include <iostream> 
#include <ctime> 
#include <cassert> 

#include "processthread.hpp" 
#include "progressevents.hpp" 

using namespace std; 
using namespace events::progress; 
 
MyDlgEx::MyDlgEx(QWidget* /*parent*/)
{
    setupUi(this); // this sets up GUI

    SetDlgFlags(); 
    CenterDlg(); 
    SetConnections(); 

    _steps = 0; 
    _progressBar->reset(); 
    _progressBar->setTextVisible(true); 
}

void MyDlgEx::SetConnections()
{
    connect(btnTest, SIGNAL(clicked()), this, SLOT(btnTest_clicked())); 
    connect(btnShowProgress, SIGNAL(clicked()), this, SLOT(btnShowProgress_clicked())); 
}

void MyDlgEx::SetDlgFlags()
{
  Qt::WindowFlags flags;
  flags = Qt::Window | Qt::WindowMinimizeButtonHint;
  setWindowFlags( flags );
}

void MyDlgEx::CenterDlg()
{
  QDesktopWidget *desktop = QApplication::desktop();
    
  int screenWidth, width; 
  int screenHeight, height;
  int x, y;
  QSize windowSize;
 
  screenWidth = desktop->width(); 
  screenHeight = desktop->height(); 
 
  windowSize = size(); // size of our application window
  width = windowSize.width(); 
  height = windowSize.height();
 
  // little computations
  x = (screenWidth - width) / 2;
  y = (screenHeight - height) / 2;
  y -= 50;
 
  // move window to desired coordinates
  move ( x, y );
}

void MyDlgEx::btnTest_clicked()
{
  QMessageBox::information(this, "hello", "Info"); 
}

void MyDlgEx::btnShowProgress_clicked()
{
    _pProc = new ProcessThread(this); 
    _pProc->run();
}

void MyDlgEx::customEvent(QEvent * e)
{
    if (e->type() == IdNumOperations)
    {
        NumOperations* pEvt = static_cast<NumOperations*>(e); 
        _progressBar->reset();
        _steps = 0; 
        cout << "Num Operations = " << pEvt->operations() << endl; 
    }
    else if (e->type() == IdStep)
    {
        //Step* pEvt = static_cast<Step*>(e); 
        if (_steps % 10 == 0)
        {
            cout << "Step++ = " << _steps << endl; 
        }

        _steps++;  
        _progressBar->setValue(_steps); 
    }
    else if (e->type() == IdCompleted)
    {
        //Completed* pEvt = static_cast<Completed*>(e); 
        cout << "Completed" << endl;
    }
    else if (e->type() == IdCanceled)
    {
        //Canceled* pEvt = static_cast<Canceled*>(e); 
        cout << "Canceled" << endl; 
    }
    else 
    {
        assert(0); 
    }
}

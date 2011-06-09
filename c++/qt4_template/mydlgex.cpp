#include <QtGui> 
#include "mydlgex.hpp" 
 
MyDlgEx::MyDlgEx(QWidget* /*parent*/)
{
    setupUi(this); // this sets up GUI

    SetDlgFlags(); 
    CenterDlg(); 
    SetConnections(); 
}
 
 
void MyDlgEx::testButton_clicked()
{
  QMessageBox::information(this, "hello", "Info"); 
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

void MyDlgEx::SetConnections()
{
    connect(testButton, SIGNAL(clicked()), this, SLOT(testButton_clicked())); 
}

#ifndef MAIN_H
#define MAIN_H
 
#include "ui_mydlgex.h"
 
 
class MyDlgEx : public QDialog, private Ui::MyDlg
{
  Q_OBJECT
 
public:
  MyDlgEx(QWidget *parent = 0);
 
 
public slots:
  void testButton_clicked(); 

private: 
  void SetDlgFlags(); 
  void CenterDlg(); 
  void SetConnections();

};
 
#endif 

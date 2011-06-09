#include <QApplication>
 
#include "mydlgex.hpp" 
 
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MyDlgEx *dialog = new MyDlgEx; 
 
    dialog->show();
    return app.exec();
}

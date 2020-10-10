#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
//    Widget test;
//    if(0)
//        test.show();


    return a.exec();
}

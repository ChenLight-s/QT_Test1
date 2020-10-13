#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
//    Widget test;
//    controlPlatform hd;
//    hd.show();
//    hd.move(100,100);

    return a.exec();
}

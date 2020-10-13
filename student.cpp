#include "student.h"
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Student::Student(QObject *parent) : QObject(parent)
{

}
void Student::treat()
{
    qDebug()<<"吃饭了";

}
//QString  → char * ，先转成 QByteArray (.toUtf8()) 再转  char *
void Student::treat(QString foodName)
{
    qDebug()<<"要吃："<<foodName.toUtf8().data();
}
void Student::btnMove(QPushButton *btn,int x,int y)
{
    //ui->setupUi(this);
    btn->move(btn->x()-120,btn->y()+50);
    if(btn->x()<=0)
    {
//        btn->move(0,btn->y());
        btn->move(x-(btn->width()),btn->y());
        qDebug()<<"左";
    }
    if((btn->y()+btn->height())>=y)
    {
//        btn->move(0,0);
        btn->move(btn->x(),0);
        qDebug()<<"下";
    }
    //qDebug()<<"x，y坐标加10";
}
void Student::btnMove1(QPushButton *btn,int x,int y)
{
    btn->move(btn->x()+50,btn->y()-100);
    if((btn->x() + btn->width())>=x)
    {
//        btn->move(0,btn->y());
        btn->move(0,btn->y());
        qDebug()<<"右";
    }
    if(btn->y()<=0)
    {
//        btn->move(0,0);
        btn->move(btn->x(),y-(btn->height()));
        qDebug()<<"上";

    }
    //qDebug()<<"x，y坐标加10";
}

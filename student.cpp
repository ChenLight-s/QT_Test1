#include "student.h"
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
void Student::btnMove(QPushButton *btn)
{
    btn->move(btn->x()+10,btn->y()+8);
    qDebug()<<"x，y坐标加10";
}

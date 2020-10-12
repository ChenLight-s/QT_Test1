#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QPaintEvent>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //创建一个老师对象
    this->yg = new Teacher(this);

    //创建一个学生对象
    this->st = new Student(this);
    //直接输出 treat 函数
   // st->treat();
    //信号和槽


    //QString  → char * ，先转成 QByteArray (.toUtf8()) 再转  char *
    void(Teacher:: *teacherSignal)(QString) = &Teacher::hungry;
    void(Student:: *btnMove) (QString)= &Student::treat;
    connect(yg,teacherSignal,st,btnMove);
/***-----------------------------------------------*******/
//问题1：信号和槽必须都不带参数或者都带参数吗;
//      如果其中一方带参数可以吗;
//问题2：参数的类型必须一样吗，不同类型的参数是否可行;
/***------------------------------------------------*******/
    void(Teacher:: *teacherSignal1)(QPushButton *) = &Teacher::hungry;
    void(Student:: *btnMove1) (QPushButton *)= &Student::btnMove;
    connect(yg,teacherSignal1,st,btnMove1);



    //QString  → char * ，先转成 QByteArray (.toUtf8()) 再转  char *
    void(Teacher:: *teacherSignal2)(void) = &Teacher::hungry;
    void(Student:: *btnMove2) (void)= &Student::treat;
    connect(yg,teacherSignal2,st,btnMove2);
    //调用函数
//    classIsOver();
    //触发信号


   //emit st->treat(0);

    //添加按键0
    QPushButton *btn0 = new QPushButton("btn0",this);
    btn0->adjustSize();
    btn0->move(100,100);




    QPushButton *closeWindown = new QPushButton("关闭",this);
    closeWindown->adjustSize();
    closeWindown->move(btn0->x()+100,btn0->y()+100);
    closeWindown->setStyleSheet(
"QPushButton{background-color:gray; border-radius: 10px; border-style: outset;}" // 按键本色
"QPushButton:hover{background-color:#ed2f6a;}"  // 鼠标停放时的色彩
"QPushButton:pressed{background-color:rgb(85, 170, 255);}");
    //void( *studentBtnMove)(QPushButton) = &Student::btnMove;


    //void(Teacher:: *teacherSignal1)(QPushButton *) = &Teacher::hungry;
    //void(Student:: *btnMove1) (QPushButton *)= &Student::btnMove;
    //QPushButton
    //connect(btn0,&QPushButton::whatsThis,st,btnMove1);
    connect(btn0,&QPushButton::clicked,st,[=](){st->btnMove(closeWindown);});
    connect(closeWindown,&QPushButton::clicked,st,[=](){st->btnMove1(closeWindown);});
    //closeWindown->setDown(true);
    //emit yg->hungry(closeWindown);
    if(closeWindown->isDown())
    {
        qDebug()<<closeWindown->isDown();
        st->btnMove(closeWindown);
    }
//    closeWindown->setStyleSheet("QPushButton{background-color:#ed2f6a;
//color: white;   border-radius: 10px;  border: 2px groove gray; border-style: outset;}" // 按键本色
//"QPushButton:hover{background-color:white; color: black;}"  // 鼠标停放时的色彩
//"QPushButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }");


}
void Widget:: classIsOver()
{
    //调用后触发信号
    emit yg->hungry("小葱拌豆腐");
}

void Widget:: classIsOver1()
{
    //调用后触发信号
    //emit yg->hungry(QPushButton::closeWindown);
}
Widget::~Widget()
{
    delete ui;
}


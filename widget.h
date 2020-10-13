#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include "teacher.h"
#include "student.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; class controlPlatform;}
//namespace Ui { class controlPlatform; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    Teacher *yg;
    Student *st;
    void classIsOver();
    void classIsOver1();
    void controlPlatform(QPushButton *btn,QWidget *wid);
};

class controlPlatform : public QWidget
{
    Q_OBJECT

public:
    controlPlatform(QWidget *parent = nullptr);
    ~controlPlatform();

private:
  //  Ui::controlPlatform *ui;
//    Ui::Widget *ui;
//    Teacher *yg;
//    Student *st;
//    void classIsOver();
//    void classIsOver1();
//    void controlPlatform(bool state);
};
#endif // WIDGET_H

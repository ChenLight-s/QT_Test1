#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>
#include <QPushButton>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);

signals:
    //自定义信号的位置
    //返回值void 只需要声明，不用实现
    //可以有参数，可以重载
    void hungry();

    void hungry(QString foodName);
    void hungry(QPushButton *Btn);

};

#endif // TEACHER_H

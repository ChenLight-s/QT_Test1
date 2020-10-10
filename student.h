#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>
#include <QPushButton>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);
    //自定义槽函数位置
    //返回值void 需要声明和实现
    //可以有参数和重载
    void treat();
    void treat(QString foodName);
    void btnMove(QPushButton *Btn);
signals:

};

#endif // STUDENT_H

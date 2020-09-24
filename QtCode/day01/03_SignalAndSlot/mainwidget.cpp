#include "mainwidget.h"
#include <QPushButton>
#include <QDebug>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{

    b1.setParent(this);
    b1.setText("close");
    b1.move(100,100);

    b2 = new QPushButton(this);
    b2->setText("abc");


    connect(&b1,&QPushButton::pressed,this,&MainWidget::close);
//自定义槽
    //槽函数与信号一致：参数、返回值
    //信号没有返回值=>槽函数没有返回值
    connect(b2,&QPushButton::released,this,&MainWidget::mySlot);

    connect(b2,&QPushButton::released,&b1,&QPushButton::hide);

    setWindowTitle("老大");
    b3.setParent(this);
    b3.setText("切换到子窗口");
    b3.move(50,50);

    //显示子窗口
    //w.show();

    connect(&b3,&QPushButton::released,this,&MainWidget::changeWin);

    //处理子窗口的信号
    connect(&w,&SubWidget::mySignal,this,&MainWidget::dealSub);
}

void MainWidget::mySlot()
{
    b2->setText("123");
}

void MainWidget::changeWin()
{
    //子窗口显示
    w.show();
    //本窗口隐藏
    this->hide();

}

void MainWidget::dealSub()
{
    //子窗口隐藏
    w.hide();
    //本窗口显示
    show();
}

MainWidget::~MainWidget()
{

}

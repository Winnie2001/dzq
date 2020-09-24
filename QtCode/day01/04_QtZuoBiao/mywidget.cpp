#include "mywidget.h"
#include <QPushButton>
#include "mybutton.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    move(100,100);


    QPushButton *b1=new QPushButton(this);
    b1->move(100,100);
    b1->setText("^_^");
    b1->resize(200,100);

    QPushButton *b2=new QPushButton(b1);
    b2->move(10,10);
    b2->setText("@_@");

    MyButton *b3=new MyButton(this);
    b3->setText("123");

}

MyWidget::~MyWidget()
{

}

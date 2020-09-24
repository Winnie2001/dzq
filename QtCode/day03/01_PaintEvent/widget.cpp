#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPushButton>
#include <QLabel>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter p(this);

    //p.drawPixmap(0,0,width(),height(),QPixmap("../Image/bg.jfif"));
    p.drawPixmap(rect(),QPixmap("../Image/bg.jfif"));



    p.end();
}

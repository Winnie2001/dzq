#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QBitmap>

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

    p.drawPixmap(0,0,QPixmap("../Image/timg.jfif"));
    p.drawPixmap(200,0,QBitmap("../Image/timg.jfif"));
    QPixmap pixmap;
    pixmap.load("../Image/timg.jfif");
    p.drawPixmap(0,200,pixmap);

    QBitmap bitmap;
    bitmap.load("../Image/timg.jfif");
    p.drawPixmap(200,200,bitmap);
}

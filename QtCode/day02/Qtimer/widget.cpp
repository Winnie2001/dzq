#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    time=new QTimer(this);
    connect(time,&QTimer::timeout,
            [=]()
            {
        static int i=0;
        i++;
        ui->lcdNumber->display(i);
        if(i==100)
            close();
            }
            );

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_start_clicked()
{
    if(time->isActive()==false)
    time->start(100);
}

void Widget::on_stop_clicked()
{
    if(time->isActive()==true)
    time->stop();
}

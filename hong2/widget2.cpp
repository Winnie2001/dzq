#include "widget2.h"
#include "ui_widget2.h"
#include <QPainter>
#include <QDebug>
#include<QPainter>

int N;
int Sum;
Widget2::Widget2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget2)
{
    ui->setupUi(this);
    ui->label_2->hide();
    ui->lineEdit->hide();
    ui->pushButton_3->hide();
}

Widget2::~Widget2()
{
    delete ui;
}


void Widget2::on_pushButton_clicked()
{
    ui->label->hide();
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->label_2->show();
    ui->lineEdit->show();
    ui->pushButton_3->show();
}

void Widget2::on_pushButton_2_clicked()
{
    this->close();
}
void Widget2::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(rect(),QPixmap(":/new/prefix1/Image/bg1.jfif"));
}
void Widget2::on_pushButton_3_clicked()
{
    N=ui->lineEdit->text().toInt();
    this->close();
    a.show();
}

#include "night.h"
#include "ui_night.h"
#include<QFont>
#include<QPalette>
#include"fayan.h"
#include<QPainter>

int f;
extern int bor;//==1,进入黑夜；==0，进入红夜；
extern float piaoNum[100];
extern QString id[100];
night::night(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::night)
{
    ui->setupUi(this);
    f=0;
    if(bor==1)
    {
        //大小
        ui->label->setText("进入黑夜");
        QFont ft1;
        ft1.setPointSize(30);
        ui->label->setFont(ft1);
        //颜色
        QPalette pa1;
        pa1.setColor(QPalette::WindowText,Qt::red);
        ui->label->setPalette(pa1);
    }
    if(bor==0)
    {
        //大小
        ui->label->setText("进入红夜");
        QFont ft2;
        ft2.setPointSize(30);
        ui->label->setFont(ft2);
        //颜色
        QPalette pa2;
        pa2.setColor(QPalette::WindowText,Qt::black);
        ui->label->setPalette(pa2);
    }
}

night::~night()
{
    delete ui;
}

void night::on_pushButton_clicked()
{
    if(bor==1&&id[ui->lineEdit->text().toInt()]=="黑牌")
        if(ui->lineEdit->text().toInt()%2==0)
            f++;
    if(bor==0&&id[ui->lineEdit->text().toInt()]=="红牌")
        if(ui->lineEdit->text().toInt()%2==0)
            f++;
    ui->lineEdit->setText("");
}
void night::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(rect(),QPixmap(":/new/prefix1/Image/bg8.jfif"));
}
void night::on_pushButton_2_clicked()
{
    this->close();
    fa=new fayan;
    fa->show();
}

#include "gameover.h"
#include "ui_gameover.h"
#include<QFont>
#include<QPainter>

extern int yes;
extern QString playId[2];
GameOver::GameOver(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameOver)
{
    ui->setupUi(this);
//    if(yes==0)
//    {
        ui->label->setText("游戏结束，"+playId[yes]+"获胜！");
        QFont ft1;
        ft1.setPointSize(36);
        ui->label->setFont(ft1);
//    }
//    if(yes==1)
//    {
//        ui->label->setText("游戏结束，红牌获胜！");
//        QFont ft2;
//        ft2.setPointSize(36);
//        ui->label->setFont(ft2);
//    }
}

GameOver::~GameOver()
{
    delete ui;
}
void GameOver::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(rect(),QPixmap(":/new/prefix1/Image/bg11.jfif"));
}

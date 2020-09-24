#include "giveida.h"
#include "ui_giveida.h"
#include <QPainter>
#include <QLabel>
#include <QtGlobal>
#include <QTime>
#include <string.h>
#include <QPixmap>
#include <QLineEdit>
#include <QCommandLinkButton>
#include <QTextEdit>
#include <QDebug>
#include<QPainter>

extern int N;
extern int Sum;
int isalive[100];
int card[100];
int red1;
int red;
int black1;
int black;
QString id[100];
float piaoNum[100];
QString playId[2]={"黑牌","红牌"};
giveida::giveida(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::giveida)
{
    ui->setupUi(this);
    Sum=N;
    ui->pushButton_2->hide();
}

giveida::~giveida()
{
    delete ui;
}
QString giveida::SetId()
{
    qsrand(time(NULL));
    int i=qrand()%2;
    QString id1=playId[i];//1为red,0为black;
    return id1;
}
void giveida::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(rect(),QPixmap(":/new/prefix1/Image/bg6.jfif"));
}
QString giveida::SetBlack()
{
    return playId[0];
}
QString giveida::SetRed()
{
    return playId[1];
}
void giveida::on_pushButton_clicked()
{
    red=0;
    black=0;
    for(int i=1;i<=N;i++)
    {
        piaoNum[i]=0;
        isalive[i]=1;
    }
    if(N%2==1)
    {
        red1=N/2+1;
        black1=N/2;
    }
    else
    {
        red1=N/2;
        black1=N/2;
    }
    for(int i=1;i<=N;i++)
        card[i]=i;
    for(int i=1;i<N+1;i++)
        {
           QTime t;
           t= QTime::currentTime();
           qsrand(t.msec()+t.second()*1000);
           int r = i+qrand()%(N+1-i);
           int temp=card[i];
           card[i]=card[r];
           card[r]=temp;
        }
    for(int i=1;i<=N;i++)
    {
        //随机id
       id[i]=giveida::SetId();
       if(red<=red1&&black<=black1)
       {
           if(id[i]=="红牌")red++;
           else black++;
        }
       if(red>red1)
       {
           id[i]=giveida::SetBlack();
       }
       if(black>black1)
        {
           id[i]=giveida::SetRed();
       }
    }
    for(int i=1;i<=N;i++)
    {
        ui->textBrowser->append("位置"+QString::number(i)+","
                                +QString::number(card[i])+"号玩家 "+id[card[i]]);
    }
    ui->textBrowser->append("获取身份完成");
    ui->pushButton_2->show();
}

void giveida::on_pushButton_2_clicked()
{
    this->close();
    a.show();
}

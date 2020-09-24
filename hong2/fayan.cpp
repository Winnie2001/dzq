#include "fayan.h"
#include "ui_fayan.h"
//#include"night.h"
#include"chosecun.h"
#include<QPainter>

extern int leader;
extern int N;
extern int flag;
extern float piaoNum[100];
extern QString id[100];
extern int isalive[100];
extern int card[100];
extern int Sum;
extern int f;
extern int black1;
extern int red1;
QString str;
int position;
int position0;
int w;
extern int bor;
int yes;
fayan::fayan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fayan)
{
    ui->setupUi(this);
    w=1;
    piaoNum[leader]+=f;
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    ui->textBrowser->append("村长选择发言顺序：");
}

fayan::~fayan()
{
    delete ui;
}

void fayan::on_pushButton_clicked()
{
    if(str=="左")
    {
        if(position==position0)
        {
            ui->textBrowser->append("位置"+QString::number(position)+","
                                    +QString::number(card[position])+"号发言:"
                                    +ui->lineEdit->text());
            ui->lineEdit->setText("");
            ui->pushButton->hide();
            ui->textBrowser->append("开始投票");
            ui->pushButton_2->show();

        }
        else if(position>0)
        {
            if(isalive[card[position]])
            {
                ui->textBrowser->append("位置"+QString::number(position)+","
                                        +QString::number(card[position])+"号发言:"
                                        +ui->lineEdit->text());
                ui->lineEdit->setText("");
            }
            else
            {
                ui->textBrowser->append("位置"+QString::number(position)+","
                                         +QString::number(card[position])+"号玩家已死亡");
//                ui->lineEdit->setText("");
            }
            position--;
        }
        if(position==0)
            position=N;
    }

    if(str=="右")
    {
        if(position==position0)
        {
            ui->textBrowser->append("位置"+QString::number(position)+","
                                    +QString::number(card[position])+"号发言:"
                                    +ui->lineEdit->text());
            ui->lineEdit->setText("");
            ui->pushButton->hide();
            ui->textBrowser->append("开始投票");
            ui->pushButton_2->show();
        }
        else if(position<=N)
        {
            if(isalive[card[position]])
            {
                ui->textBrowser->append("位置"+QString::number(position)+","
                                        +QString::number(card[position])+"号发言:"
                                        +ui->lineEdit->text());
                ui->lineEdit->setText("");
            }
            else
            {
                ui->textBrowser->append("位置"+QString::number(position)+","
                                         +QString::number(card[position])+"号玩家已死亡");
                ui->lineEdit->setText("");
            }
            position++;
        }
        if(position>N)
            position=1;
    }
}

void fayan::on_pushButton_4_clicked()
{
    ui->textBrowser->append(ui->lineEdit->text());
    str=ui->lineEdit->text();
    for(int i=1;i<=N;i++)
    {
        if(card[i]==leader)
        {
            position0=i;
            if(str=="左")
            {
                position=i-1;
                break;
            }
            else
            {
                position=i+1;
                break;
            }
        }
        else
            continue;
    }
    ui->pushButton->show();
    ui->lineEdit->setText("");
    ui->pushButton_4->hide();
}
void fayan::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(rect(),QPixmap(":/new/prefix1/Image/bg9.jfif"));
}
void fayan::on_pushButton_2_clicked()
{

        if(isalive[w]==1)
        {
            ui->textBrowser->append("投票给"+ui->lineEdit->text()+"号");
            int l=ui->lineEdit->text().toInt();
            if(w==leader)
            {
                piaoNum[l]+=changeP(Sum);
            }
            else
                piaoNum[l]++;
            ui->lineEdit->setText("");
            w++;
        }
        else
            w++;

    if(w==N+1)
    {
        ui->pushButton_2->hide();
        ui->pushButton_3->show();
    }
}
float fayan::changeP(int n)
{
    if(n%2==0)
        return 1.5;
    else
        return 0.5;
}
void fayan::on_pushButton_3_clicked()
{
    int out=fayan::Sort(piaoNum);
    ui->textBrowser->setText("");
    for(int p=1;p<=N;p++)
    {
        if(piaoNum[out]==piaoNum[p]/*&&isalive[p]==1*/)
        {
            ui->textBrowser->append(QString::number(p)+"号玩家被放逐,"
                                    +"身份为"+id[p]);
            isalive[p]=0;
            Sum--;
            if(id[p]=="黑牌")
                black1--;
            else
                red1--;

            if(p==leader)
            {
                ui->textBrowser->append("村长被放逐");
                flag=0;
            }
        }
        if(p==N)
            ui->pushButton_5->show();
    }
    if(flag==0)
    {
        ui->pushButton_5->hide();
        ui->pushButton_6->show();
    }

    if(black1==0||red1==0)
    {
        if(red1==0)
            yes=1;
        else
            yes=0;
        ui->pushButton_3->hide();
        ui->pushButton_5->hide();
        ui->pushButton_6->hide();
        ui->lineEdit->hide();
        ui->pushButton_7->show();
    }
    for(int i=1;i<=N;i++)
        piaoNum[i]=0;
}
int fayan::Sort(float a[])
{
        int value=1;
        int len=N;
        for(int i=1;i<=N;i++)
        {
            if(a[i]>a[value])
                value=i;
        }
        return value;
}
int fayan::EnterBlack(){
    qsrand(time(NULL));
    return qrand()%2;
}
void fayan::on_pushButton_5_clicked()
{

    this->close();
    for(int i=1;i<=N;i++)
        piaoNum[i]=0;
    bor=fayan::EnterBlack();
    a.show();
}

void fayan::on_pushButton_6_clicked()
{
    this->close();
    for(int i=1;i<=N;i++)
        piaoNum[i]=0;
    c=new chosecun;
    c->show();
}

void fayan::on_pushButton_7_clicked()
{
    this->close();
    qt.show();
}

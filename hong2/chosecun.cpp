#include "chosecun.h"
#include "ui_chosecun.h"
#include<string.h>
#include<QPainter>

extern int N;
extern float piaoNum[100];
extern int isalive[100];
extern int card[100];
extern int Sum;
int flag=0;
int i;
int j;
int leader; 
int bor;
chosecun::chosecun(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chosecun)
{
    ui->setupUi(this);
    i=1;j=1;
    for(int k=1;k<=N;k++)
        piaoNum[k]=0;
    ui->label_2->hide();
    ui->pushButton_2->hide();
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
}

chosecun::~chosecun()
{
    delete ui;
}
int chosecun::Sort(float a[]) {
    int value=1;
//    int len=sizeof(a);
    for(int k=2; k<=N; k++)
    {
        if(a[k]>a[value])
            value=k;
    }
    return value;
}
void chosecun::on_pushButton_clicked()
{
        ui->textBrowser->append(ui->lineEdit->text());
        ui->lineEdit->setText("");
        i++;
        if(i>N)
        {
            i=1;
            ui->label_2->show();
            ui->pushButton->hide();
            ui->pushButton_2->show();
        }
        else
        {
            if(isalive[i])
            {
                for(int x=1;x<=N;x++)
                {
                    if(card[x]==i)
                    {
                        ui->textBrowser->append("位置"+QString::number(x)+","
                                                +QString::number(i)+"号请发言");
                        break;
                    }
                }
            }
            else
                ui->textBrowser->append(QString::number(i)+"号已死亡");
        }
}

void chosecun::on_pushButton_2_clicked()
{
//    if(j<=N)
//    {
        if(isalive[j])
        {
            int l=ui->lineEdit->text().toInt();
            ui->textBrowser->append("投票给"+ui->lineEdit->text()+"号");
            piaoNum[l]++;
            ui->lineEdit->setText("");
            j++;
        }
        else
            j++;

//    }
    if(j>N)
    {
        j=1;
        ui->pushButton_5->show();
        ui->pushButton_2->hide();
    }
}
void chosecun::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(rect(),QPixmap(":/new/prefix1/Image/bg2.jfif"));
}
void chosecun::on_pushButton_3_clicked()
{
    for(int m=1;m<=N;m++)
        piaoNum[m]=0;
    for(i=1;i<=N;i++)
    {
        if(isalive[i]==1)
        {
            for(int x=1;x<=N;x++)
            {
                if(card[x]==i)
                {
                    ui->textBrowser->append("位置"+QString::number(x)+","
                                            +QString::number(i)+"号请发言");
                    ui->pushButton_3->hide();
                    break;
                }
            }
            break;
        }
        else
        {
            for(int x=1;x<=N;x++)
            {
                if(card[x]==i)
                {
                     ui->textBrowser->append("位置"+QString::number(x)+","+
                                             QString::number(i)+"号已死亡");
                }
            }
        }
    }
}
void chosecun::on_pushButton_5_clicked()
{

    leader=chosecun::Sort(piaoNum);
    flag=1;
    ui->textBrowser->append("村长是"+QString::number(leader)+"号");
    ui->pushButton_4->show();
}
void chosecun::on_pushButton_4_clicked()
{
    this->close();
    for(int p=1;p<=N;p++)
    {
        piaoNum[p]=0;
    }
    a.show();
}



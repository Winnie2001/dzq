#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QCompleter>
#include<QStringList>
#include<QMovie>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->button->setText("123");
    //connect(ui->button,&QPushButton::clicked,this,&MainWindow::close);
    //lineEdit
    QString str=ui->lineEdit->text();
    qDebug()<<str;
    ui->lineEdit->setText("qwe");
    ui->lineEdit->setTextMargins(15,0,0,0);
    //ui->lineEdit->setEchoMode(QLineEdit::Password);
    //list下拉框提示
    QStringList list;
    list<<"hello"<<"How are you"<<"hehe";
    QCompleter *com=new QCompleter(list,this);
    com->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(com);
    //label文本编辑
    ui->labeltext->setText("^_^");
    //label图片
    ui->labelImage->setPixmap(QPixmap("://Image/timg.jfif"));
    ui->labelImage->setScaledContents(true);
    //label动图
    QMovie *mymovie=new QMovie("://Image/timg.gif");
    ui->labelGif->setMovie(mymovie);
    ui->labelGif->setScaledContents(true);
    mymovie->start();
    //label链接
    ui->labelUrl->setText("<h1><a href=\"http://www.baidu.com\">百度一下</a></h1>");
    ui->labelUrl->setOpenExternalLinks(true);
    //数码管
    ui->lcdNumber->display(123);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(200);
    ui->progressBar->setValue(100);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{
    static int i = 0;
    ui->stackedWidget->setCurrentIndex( ++i %4);






}

void MainWindow::on_change_clicked()
{
    static int i=0;
    ui->stackedWidget->setCurrentIndex(++i%4);
}

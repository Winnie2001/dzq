#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
#include <QKeyEvent>
#include <QCloseEvent>
#include <QMessageBox>
#include <QEvent>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    timeId= this->startTimer(1000);
    timeId2=this->startTimer(500);
    connect(ui->pushButton, &MyButton::clicked,
            [=]()
            {
                qDebug()<<"按钮被按下";
            }

            );
    //安装过滤器
    ui->label_2->installEventFilter(this);
    ui->label_2->setMouseTracking(true);

}

MyWidget::~MyWidget()
{
    delete ui;
}
void MyWidget::keyPressEvent(QKeyEvent *event)
{
    qDebug() << event->key();

    if(event->key()==Qt::Key_A)
    {
        qDebug()<<"Qt::Key_A";
    }
}

void MyWidget::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==this->timeId)
    {
        static int sec=0;
        ui->label->setText(
             QString("<center><h1>timer out:%1</h1></center>").arg(sec++));

        if(5==sec){
            this->killTimer(this->timeId);
        }
    }
    else if(event->timerId()==this->timeId2)
    {
        static int sec = 0;
        ui->label_2->setText(
                    QString("<center><h1>timer out: %1</h1><cenetr>").arg(sec++)
                    );
    }
}

void MyWidget::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"++++++++++";
}

void MyWidget::closeEvent(QCloseEvent *event)
{
   int ret = QMessageBox::question(this,"question","是否需要关闭窗口");
    if(ret == QMessageBox::Yes)
    {
            event->accept();

    }
            else
    {
            event->ignore();
    }

}

bool MyWidget::event(QEvent *event)
{

    //事件分发
 //   switch(event->type())
  //  {
   //     case QEvent::Close:
   //     closeEvent(event);
   //             break;
   // case QEvent::MouseMove:
    //   mouseMoveEvent(event);
//        break;
    /*
    *.....
    */
//    }
     if (event->type()== QEvent::Timer)
     {
         //QTimerEvent *env = static_cast<QTimerEvent *>(event);
         //timerEvent(env);
         return true;
     }
     else if(event->type()== QEvent::KeyPress)
     {
         QKeyEvent *env = static_cast<QKeyEvent *>(event);
         if(env->key()==Qt::Key_B)
         {
             return QWidget::event(event);
         }
         return true;
     }
     else
     {
         return QWidget::event(event);
     }

}
bool MyWidget::eventFilter(QObject *obj, QEvent *e)
{
    if(obj == ui->label_2)
    {
        QMouseEvent *env = static_cast<QMouseEvent *>(e);
        //判断事件
        if(e->type() == QEvent::MouseMove)
        {
            ui->label_2->setText(QString("Mouse move:(%1,%2)").arg(env->x()).arg(env->y()));
            return true;
        }
        if(e->type() == QEvent::MouseButtonPress)
        {
            ui->label_2->setText(QString("Mouse press:(%1,%2)").arg(env->x()).arg(env->y()));
            return true;
        }
        if(e->type() == QEvent::MouseButtonRelease)
        {
            ui->label_2->setText(QString("Mouse release:(%1,%2)").arg(env->x()).arg(env->y()));
            return true;
        }
        else
        {
             return QWidget::eventFilter(obj,e);
        }
    }
    else
    {
        return QWidget::eventFilter(obj,e);
    }

}

#include "mylabel.h"
#include <QMouseEvent>
#include <QDebug>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    //追踪鼠标
    this->setMouseTracking(true);
}
void MyLabel:: mousePressEvent(QMouseEvent *ev)
{
    int i=ev->x();
    int j=ev->y();
    //sprinf
    /*
     * Qstring str=Qstring("abc %1 ^_^ %2").arg(123).arg("mike");
     * str=abc 123 ^_^ mike
    */


    if(ev->button()==Qt::LeftButton)
    {
       qDebug()<<"left";
    }else if(ev->button()==Qt::RightButton)
    {
        qDebug()<<"right";
    }else if(ev->button()==Qt::MidButton)
    {
        qDebug()<<"mid";
    }
    QString text=QString("<center><hi>Mouse press:(%1,%2)</hi></center>")
            .arg(i).arg(j);
    this->setText(text);

}

void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    QString text=QString("<center><hi>Mouse Release:(%1,%2)</hi></center>")
            .arg(ev->x()).arg(ev->y());
    this->setText(text);
}

void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    QString text=QString("<center><hi>Mouse Move:(%1,%2)</hi></center>")
            .arg(ev->x()).arg(ev->y());
    //this->setText(text);
}

void MyLabel::enterEvent(QEvent *event)
{
    QString text=QString("<center><hi>Mouse enter:</hi></center>");
    this->setText(text);
}
void MyLabel::leaveEvent(QEvent *event)
{
    QString text=QString("<center><hi>Mouse leave:</hi></center>");
    this->setText(text);
}

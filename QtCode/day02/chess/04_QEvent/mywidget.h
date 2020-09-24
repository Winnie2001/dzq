#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();

private:
    void keyPressEvent(QKeyEvent *event);

    void timerEvent(QTimerEvent *event);

    void mousePressEvent(QMouseEvent *event);

    void closeEvent(QCloseEvent *event);

    bool event(QEvent *event);

    bool eventFilter(QObject *obj, QEvent *e);

private:
    Ui::MyWidget *ui;

    int timeId;
    int timeId2;
};

#endif // MYWIDGET_H

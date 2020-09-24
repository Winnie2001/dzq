#ifndef WIDGET2_H
#define WIDGET2_H

#include <QWidget>
#include"giveida.h"

namespace Ui {
class Widget2;
}

class Widget2 : public QWidget
{
    Q_OBJECT

public:
    explicit Widget2(QWidget *parent = 0);
    ~Widget2();

protected:
    void paintEvent(QPaintEvent *);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Widget2 *ui;
    giveida a;

};

#endif // WIDGET2_H

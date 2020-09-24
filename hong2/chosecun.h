#ifndef CHOSECUN_H
#define CHOSECUN_H

#include <QWidget>
#include"fayan.h"

namespace Ui {
class chosecun;
}

class chosecun : public QWidget
{
    Q_OBJECT

public:
    explicit chosecun(QWidget *parent = 0);
    ~chosecun();

    int Sort(float a[]);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();
protected:
    void paintEvent(QPaintEvent *);
private:
    Ui::chosecun *ui;
    fayan a;

};

#endif // CHOSECUN_H

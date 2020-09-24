#ifndef FAYAN_H
#define FAYAN_H
//class night;
class chosecun;
#include <QWidget>
#include"night.h"
//#include"chosecun.h"
#include"gameover.h"


namespace Ui {
class fayan;
}

class fayan : public QWidget
{
    Q_OBJECT

public:
    explicit fayan(QWidget *parent = 0);
    ~fayan();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    float changeP(int n);

    void on_pushButton_3_clicked();

    int Sort(float a[]);

    void on_pushButton_5_clicked();

    int EnterBlack();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();
protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::fayan *ui;
    night a;
    chosecun *c;
//    chosecun *c;
    GameOver qt;
};

#endif // FAYAN_H

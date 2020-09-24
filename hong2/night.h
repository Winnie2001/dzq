#ifndef NIGHT_H
#define NIGHT_H
class fayan;
#include <QWidget>
//#include"fayan.h"


namespace Ui {
class night;
}

class night : public QWidget
{
    Q_OBJECT

public:
    explicit night(QWidget *parent = 0);
    ~night();

protected:
    void paintEvent(QPaintEvent *);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::night *ui;
    fayan *fa;
};

#endif // NIGHT_H

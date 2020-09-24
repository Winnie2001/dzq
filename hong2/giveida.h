#ifndef GIVEIDA_H
#define GIVEIDA_H

#include <QWidget>

#include <QString>
#include <QLineEdit>
#include"chosecun.h"

namespace Ui {
class giveida;
}

class giveida : public QWidget
{
    Q_OBJECT

public:
    explicit giveida(QWidget *parent = 0);
    ~giveida();
protected:
    void paintEvent(QPaintEvent *);

public:
    void giveId(int n);
    QString SetId();
    QString SetBlack();
    QString SetRed();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::giveida *ui;
    chosecun a;

};

#endif // GIVEIDA_H

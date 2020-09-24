#ifndef CHESS_H
#define CHESS_H

#include <QWidget>

namespace Ui {
class chess;
}

class chess : public QWidget
{
    Q_OBJECT

public:
    explicit chess(QWidget *parent = 0);
    ~chess();

private:
    Ui::chess *ui;
};

#endif // CHESS_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>


int main(int argc,char **argv){

    QApplication app(argc,argv);

    QWidget a;
    a.setWindowTitle(QString("小小白"));


    QPushButton b;
    b.setText("^_^");


    b.setParent(&a);
    b.move(250,250);

    QPushButton b1(&a);
    b1.setText("abc");

    a.show();


    app.exec();
    return 0;
}

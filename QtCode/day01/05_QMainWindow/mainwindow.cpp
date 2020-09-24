#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    //菜单栏
    QMenuBar *mBar=menuBar();
    //添加菜单
    QMenu *pFile = mBar->addMenu("文件");
    //添加菜单项
    QAction *pNew = pFile->addAction("新建");

    connect(pNew,&QAction::triggered,
            [=]()
            {
            qDebug()<<"新建被摁下";
            }

            );

    pFile->addSeparator();//添加分割线

    QAction *pOpen = pFile->addAction("打开");

    //工具栏
    QToolBar *toolBar = addToolBar("toolbar");

    //工具栏添加快捷键
    toolBar->addAction(pNew);

    QPushButton *b= new QPushButton(this);
    b->setText("^_^");
    //添加小控件
    toolBar->addWidget(b);

    connect(b,&QPushButton::clicked,
            [=]()
    {
            b->setText("123");
    }
            );

    //状态栏
    QStatusBar *sBar =statusBar();
    QLabel *label = new QLabel(this);
    label->setText("Normal text file");
    sBar->addWidget(label);

    sBar->addWidget(new QLabel("2",this));
    sBar->addPermanentWidget(new QLabel("3",this));
    sBar->addPermanentWidget(new QLabel("6",this));
    //核心控件
    QTextEdit *textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);

    //浮动窗口
    QDockWidget *dock= new QDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea,dock);

    QTextEdit *textEdit1 = new QTextEdit(this);
    dock->setWidget(textEdit1);

}

MainWindow::~MainWindow()
{

}

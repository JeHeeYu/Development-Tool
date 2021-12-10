#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    toolbar = new QToolBar(this);

    act[0] = new QAction(QIcon("Image/Image.JPG"), "Broswer", this);
    act[1] = new QAction(QIcon("Image/Image.JPG"), "calendar", this);
    act[2] = new QAction(QIcon("Image/Image.JPG"), "chat", this);
    act[3] = new QAction(QIcon("Image/Image.JPG"), "editor", this);
    act[4] = new QAction(QIcon("Image/Image.JPG"), "mail", this);

    act[0]->setShortcut(Qt::Key_Control | Qt::Key_E);
    act[0]->setToolTip("This is a ToolTip");

    toolbar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    for(int i = 0; i < 5; i++)
    {
        toolbar->addAction(act[i]);
    }

    connect(act[0], SIGNAL(trigger()), this, SLOT(trigger1()));
    connect(act[1], SIGNAL(trigger()), this, SLOT(trigger2()));
    connect(act[2], SIGNAL(trigger()), this, SLOT(trigger3()));
    connect(act[3], SIGNAL(trigger()), this, SLOT(trigger4()));
    connect(act[4], SIGNAL(trigger()), this, SLOT(trigger5()));

}

MainWindow::~MainWindow()
{
   delete ui;
}

void MainWindow::trigger1()
{
    qDebug("Tool Button 1 Click");
}

void MainWindow::trigger2()
{
    qDebug("Tool Button 2 Click");
}

void MainWindow::trigger3()
{
    qDebug("Tool Button 3 Click");
}

void MainWindow::trigger4()
{
    qDebug("Tool Button 4 Click");
}

void MainWindow::trigger5()
{
    qDebug("Tool Button 5 Click");
}

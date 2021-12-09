#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    lcd[0] = new QLCDNumber(2, this);
    lcd[0]->display(24);
    lcd[0]->setGeometry(150, 30, 200, 100);
    lcd[0]->setSegmentStyle(QLCDNumber::Outline);

    lcd[1] = new QLCDNumber(5, this);
    lcd[1]->display("10:34");
    lcd[1]->setGeometry(150, 140, 200, 100);
    lcd[1]->setSegmentStyle(QLCDNumber::Filled);

    lcd[2] = new QLCDNumber(5, this);
    lcd[2]->display("10:34");
    lcd[2]->setGeometry(150, 250, 200, 100);
    lcd[2]->setSegmentStyle(QLCDNumber::Flat);
}

MainWindow::~MainWindow()
{
    delete ui;
}

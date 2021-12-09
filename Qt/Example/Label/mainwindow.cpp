#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    lb = new QLabel("Hello World!", this);
    lb->setGeometry(10, 30, 130, 40);
}

MainWindow::~MainWindow()
{
    delete ui;
}

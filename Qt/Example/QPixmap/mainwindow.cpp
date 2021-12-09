#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix = QPixmap("D:/Image/Image.JPG");
    lb = new QLabel(this);
    lb->setPixmap(pix);
    lb->setGeometry(10, 70, 100, 100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

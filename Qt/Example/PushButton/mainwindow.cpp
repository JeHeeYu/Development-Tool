#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int ypos = 30;

    for(int i = 0; i < 3; i++)
    {
        btn[i] = new QPushButton(QString("Frame's button %1").arg(i), this);
        btn[i]->setGeometry(10, ypos, 300, 40);

        ypos += 50;
    }

    connect(btn[0], &QPushButton::clicked, this, &MainWindow::btn_click);
    connect(btn[0], &QPushButton::pressed, this, &MainWindow::btn_pressed);
    connect(btn[0], &QPushButton::released, this, &MainWindow::btn_released);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::btn_click()
{
    qDebug("Button Click");
}

void MainWindow::btn_pressed()
{
    qDebug("Button Pressed");
}

void MainWindow::btn_released()
{
    qDebug("Button Released");
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int ypos = 30;

    btn = new QPushButton(QString("Example"), this);
    btn->setGeometry(10, ypos, 300, 40);

    connect(btn, &QPushButton::clicked, this, &MainWindow::btn_click);
    connect(btn, &QPushButton::pressed, this, &MainWindow::btn_pressed);
    connect(btn, &QPushButton::released, this, &MainWindow::btn_released);

    frame = new QFocusFrame(this);
    frame->setWidget(btn);
    frame->setAutoFillBackground(true);
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

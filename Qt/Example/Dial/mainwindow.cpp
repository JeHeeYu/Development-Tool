#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int xpos = 30;

    for(int i = 0; i < 3; i++, xpos += 110)
    {
        dial[i] = new QDial(this);
        dial[i]->setRange(0, 100);
        dial[i]->setGeometry(xpos, 30, 100, 100);
    }

    dial[0]->setNotchTarget(true);
    connect(dial[0], &QDial::valueChanged, this, &MainWindow::changedDate);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changedDate()
{
    qDebug("QDial 1 Value : %d", dial[0]->value());
}

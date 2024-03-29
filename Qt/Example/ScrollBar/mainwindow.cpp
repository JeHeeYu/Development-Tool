#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int xpos = 10, ypos = 50;

    for(int i = 0; i < 3; i++)
    {
        vscrollbar[i] = new QScrollBar(Qt::Vertical, this);
        vscrollbar[i]->setRange(0, 100);
        vscrollbar[i]->setGeometry(xpos, 30, 20, 200);

        lb[i] = new QLabel(QString("%1").arg(vscrollbar[i]->value()), this);
        lb[i]->setGeometry(xpos + 2, 220, 30, 30);
        xpos += 50;

        hscrollbar[i] = new QScrollBar(Qt::Horizontal, this);
        hscrollbar[i]->setRange(0, 100);
        hscrollbar[i]->setGeometry(150, ypos, 200, 20);
        ypos += 30;
    }

    connect(vscrollbar[0], SIGNAL(valueChanged(int)), this, SLOT(valueChanged1(int)));
    connect(vscrollbar[1], SIGNAL(valueChanged(int)), this, SLOT(valueChanged2(int)));
    connect(vscrollbar[2], SIGNAL(valueChanged(int)), this, SLOT(valueChanged3(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::valueChanged1(int value)
{
    lb[0]->setText(QString("%1").arg(value));
    hscrollbar[0]->setValue(vscrollbar[0]->value());
}

void MainWindow::valueChanged2(int value)
{
    lb[1]->setText(QString("%1").arg(value));
    hscrollbar[1]->setValue(vscrollbar[1]->value());
}

void MainWindow::valueChanged3(int value)
{
    lb[2]->setText(QString("%1").arg(value));
    hscrollbar[2]->setValue(vscrollbar[2]->value());
}

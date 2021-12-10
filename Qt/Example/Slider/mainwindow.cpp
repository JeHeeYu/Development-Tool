#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int xpos = 20, ypos = 20;

    for(int i = 0; i < 6; i++)
    {
        if(i <= 2)
        {
            slider[i] = new QSlider(Qt::Vertical, this);
            slider[i]->setGeometry(xpos, 20, 30, 80);
            xpos += 30;
        }

        else if(i >= 3)
        {
            slider[i] = new QSlider(Qt::Horizontal, this);
            slider[i]->setGeometry(130, ypos, 80, 30);
            ypos += 30;
        }

        slider[i]->setRange(0, 100);
        slider[i]->setValue(50);
    }

    xpos = 20;

    for(int i = 0; i < 3; i++)
    {
        lb[i] = new QLabel(QString("%1").arg(slider[i]->value()), this);
        lb[i]->setGeometry(xpos+10, 100, 30, 40);
        xpos += 30;
    }

    connect(slider[0], SIGNAL(valueChanged(int)), this, SLOT(valueChanged1(int)));
    connect(slider[1], SIGNAL(valueChanged(int)), this, SLOT(valueChanged2(int)));
    connect(slider[2], SIGNAL(valueChanged(int)), this, SLOT(valueChanged3(int)));
}

MainWindow::~MainWindow()
{
   delete ui;
}

void MainWindow::valueChanged1(int value)
{
    lb[0]->setText(QString("%1").arg(value));
    slider[3]->setValue(slider[0]->value());
}

void MainWindow::valueChanged2(int value)
{
    lb[1]->setText(QString("%1").arg(value));
    slider[4]->setValue(slider[1]->value());
}

void MainWindow::valueChanged3(int value)
{
    lb[2]->setText(QString("%1").arg(value));
    slider[5]->setValue(slider[2]->value());
}

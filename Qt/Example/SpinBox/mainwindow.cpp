#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int ypos = 30;
    int val[3] = {50, 100, 200};

    for(int i = 0; i < 3; i++)
    {
        spin[i] = new QSpinBox(this);
        spin[i]->setMinimum(10);
        spin[i]->setMaximum(300);
        spin[i]->setValue(val[i]);
        spin[i]->setGeometry(10, ypos, 100, 30);
        spin[i]->setPrefix("% ");

        ypos += 40;
    }

    connect(spin[0], SIGNAL(valueChanged(int)), this, SLOT(valueChange()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::valueChange()
{
    qDebug("Change Value : %d", spin[0]->value());
}

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
        doublespin[i] = new QDoubleSpinBox(this);
        doublespin[i]->setMinimum(10.0);
        doublespin[i]->setMaximum(300.0);
        doublespin[i]->setValue(val[i]);
        doublespin[i]->setGeometry(10, ypos, 100, 30);
        doublespin[i]->setPrefix("% ");

        ypos += 40;
    }

    connect(doublespin[0], SIGNAL(valueChanged(double)), this, SLOT(valueChange()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::valueChange()
{
    qDebug("Change Value : %3.2f", doublespin[0]->value());
}

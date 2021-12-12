#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    box = new QToolBox(this);
    lay = new QHBoxLayout(this);

    btn1 = new QPushButton("DataBase : 1", this);
    btn2 = new QPushButton("Network : 2", this);
    btn3 = new QPushButton("Grpahics : 3", this);

    box->addItem(btn1, "DabaBase");
    box->addItem(btn2, "Network");
    box->addItem(btn3, "Graphics");

    lay->addWidget(box);
    setLayout(lay);

    connect(box, SIGNAL(currentChanged(int)), this, SLOT(changedTab(int)));
}

MainWindow::~MainWindow()
{
   delete ui;
}

void MainWindow::changedTab(int index)
{
    qDebug("Curtrrent Tab : %d", index);
}

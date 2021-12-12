#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tab = new QTabBar(this);

    tab->addTab("Broswer");
    tab->addTab("User");
    tab->addTab("Application");

    tab->setShape(QTabBar::RoundedNorth);
    tab->setGeometry(20, 20, 300, 250);

    connect(tab, SIGNAL(currentchanged(int)), this, SLOT(currentTab(int)));
}

MainWindow::~MainWindow()
{
   delete ui;
}

void MainWindow::currentTab(int index)
{
    qDebug("Curtrrent Tab : %d", index);
}

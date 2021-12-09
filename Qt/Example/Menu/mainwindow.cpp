#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    menuBar = new QMenuBar(this);

    menu[0] = new QMenu("File");
    menu[0]->addAction("Edit");
    menu[0]->addAction("View");
    menu[0]->addAction("Tools");

    act[0] = new QAction("New", this);
    act[0]->setShortcut(Qt::CTRL | Qt::Key_A);
    act[0]->setStatusTip("This is a New menu.");

    act[1] = new QAction("Open", this);
    act[1]->setCheckable(true);

    menu[1] = new QMenu("Save");
    menu[1]->addAction(act[0]);
    menu[1]->addAction(act[1]);

    menu[2] = new QMenu("Print");
    menu[2]->addAction("Page Setup");
    menu[2]->addMenu(menu[1]);

    menuBar->addMenu(menu[0]);
    menuBar->addMenu(menu[1]);
    menuBar->addMenu(menu[2]);

    lb = new QLabel("", this);

    connect(menuBar, SIGNAL(triggered(QAction*)), this, SLOT(trigerMenu(QAction*)));

    menuBar->setGeometry(0, 0, 600, 40);
    lb->setGeometry(10, 200, 200, 40);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::trigerMenu(QAction *act)
{
    QString str = QString("Selected Menu : %1").arg(act->text());
    lb->setText(str);
}

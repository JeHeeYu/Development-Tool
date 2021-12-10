#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int ypos = 30;

    tab->addTab(broswer, QIcon("Image/Image.jpg"), "Broswer");
    tab->addTab(user, QIcon("Image/Image.jpg"), "Users");

    tab->setGeometry(20, 20, 300, 250);

    for(int i = 0; i < 3; i++)
    {
        btn[i] = new QPushButton(btn_str[i], broswer);
        btn[i]->setGeometry(10, ypos, 100, 40);

        ypos += 50;
    }

    connect(tab, SIGNAL(currentChanged(int)), this, SLOT(currentTab(int)));
}

MainWindow::~MainWindow()
{
   delete ui;
}

void MainWindow::currentTab(int index)
{
    qDebug("Current Tab : %d", index);
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tool = new QToolBar(this);
    layout = new QVBoxLayout;

    for(int i = 0; i < 3; i++)
    {
        btn[i] = new QToolButton;
    }

    tool->addWidget(btn[0]);
    tool->addWidget(btn[1]);
    tool->addWidget(btn[2]);

    tool->addSeparator();
    layout->addWidget(tool);

    this->setLayout(layout);
}

MainWindow::~MainWindow()
{
   delete ui;
}


#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSizeGrip *sizegrip = new QSizeGrip(this);
    sizegrip->setFixedSize(sizegrip->sizeHint());

    this->setLayout(new QVBoxLayout);
    this->layout()->setMargin(0);

    layout()->addWidget(new QTextEdit);

    sizegrip->setWindowFlags(Qt::WindowStaysOnTopHint);
    sizegrip->raise();
}

MainWindow::~MainWindow()
{
   delete ui;
}

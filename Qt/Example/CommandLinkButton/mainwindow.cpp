#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(QSize(300, 100));

    cmmBtn = new QCommandLinkButton("example", this);
    cmmBtn->setFlat(true);

    connect(cmmBtn, SIGNAL(clicked()), this, SLOT(clickFunc()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clickFunc()
{
    qDebug("QCommandLinkButton Click");
}

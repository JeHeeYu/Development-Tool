#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    combo = new QComboBox(this);
    combo->setGeometry(50, 50, 200, 30);
    combo->addItem("Application");
    combo->addItem("Graphics");
    combo->addItem("Database");
    combo->addItem("Network");
}

MainWindow::~MainWindow()
{
    delete ui;
}

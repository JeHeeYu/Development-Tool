#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qde[0] = new QDateTimeEdit(QDateTime::currentDateTime(), this);
    qde[0]->setDisplayFormat("yyyy-MM-dd hh:mm:ss:zzz");
    qde[0]->setGeometry(10, 30, 250, 30);

    qde[1] = new QDateTimeEdit(QDate::currentDate(), this);
    qde[1]->setMinimumDate(QDate::currentDate().addYears(-3));
    qde[1]->setMaximumDate(QDate::currentDate().addYears(3));
    qde[1]->setDisplayFormat("yyyy");
    qde[1]->setGeometry(10, 90, 100, 30);

    qde[2] = new QDateTimeEdit(QDate::currentDate(), this);
    qde[2]->setMinimumDate(QDate::currentDate().addMonths(-2));
    qde[2]->setMaximumDate(QDate::currentDate().addMonths(2));
    qde[2]->setDisplayFormat("MM");
    qde[2]->setGeometry(120, 90, 100, 30);

    qde[3] = new QDateTimeEdit(QDate::currentDate(), this);
    qde[3]->setMinimumDate(QDate::currentDate().addDays(-20));
    qde[3]->setMaximumDate(QDate::currentDate().addDays(20));
    qde[3]->setDisplayFormat("dd");
    qde[3]->setGeometry(230, 90, 100, 30);
}

MainWindow::~MainWindow()
{
    delete ui;
}

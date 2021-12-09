#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ti1 = QTime(6, 24, 0, 0);

    qte[0] = new QTimeEdit(ti1, this);
    qte[0]->setGeometry(10, 30, 150, 30);

    // ti1에 시간 추가
    t = ti1.addSecs(70);

    qte[1] = new QTimeEdit(t, this);
    qte[1]->setGeometry(10, 70, 150, 30);

    qte[2] = new QTimeEdit(ti1.addSecs(2000), this);
    qte[2]->setGeometry(10, 110, 150, 30);

    // 현재 시간 대입
    ti2 = QTime::currentTime();

    // 현재 시간 출력
    qte[3] = new QTimeEdit(ti2.currentTime(), this);
    qte[3]->setGeometry(10, 150, 150, 30);

    // 현재 시간 출력
    qDebug("Hour : %d", ti2.hour());
    qDebug("Hour : %d", ti2.minute());
    qDebug("Hour : %d", ti2.second());
    qDebug("Hour : %d", ti2.msec());

    ti3 = QTime::fromString("03:32", "hh:mm");

    lb[0] = new QLabel(ti3.toString(), this);
    lb[0]->setGeometry(10, 190, 150, 30);

    ti4 = QTime(7, 10, 23, 122);

    lb[1] = new QLabel(ti4.toString("AP hh:mm:ss:zzz"), this);
    lb[1]->setGeometry(10, 10, 150, 30);

    ti5 = QTime(6, 25, 34, 323);

    qDebug("Hour : %d", ti5.hour());
    qDebug("Hour : %d", ti5.minute());
    qDebug("Hour : %d", ti5.second());
    qDebug("Hour : %d", ti5.msec());
}

MainWindow::~MainWindow()
{
    delete ui;
}

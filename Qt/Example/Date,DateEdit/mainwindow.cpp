#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDate dt1 = QDate(2022, 1, 1);
    QDate dt2 = QDate::currentDate();

    dateEdit[0] = new QDateEdit(dt1.addYears(2), this);
    dateEdit[0]->setGeometry(10, 10, 140, 40);

    dateEdit[1] = new QDateEdit(dt1.addMonths(3), this);
    dateEdit[1]->setGeometry(160, 10, 140, 40);

    dateEdit[2] = new QDateEdit(dt1.addDays(5), this);
    dateEdit[2]->setGeometry(310, 10, 140, 40);

    dateEdit[3] = new QDateEdit(dt2, this);
    dateEdit[3]->setGeometry(10, 60, 140, 40);

    qDebug("Day of year : %d", dt1.dayOfYear());
    qDebug("End Day : %d", dt1.daysInMonth());
    qDebug("End Day : %d", dt1.daysInYear());

    QDate dt3 = QDate::fromString("2002.06.26", "yyyy.MM.dd");
    QDate dt4 = QDate::fromString("06.26", "MM.dd");

    lb[0] = new QLabel(dt3.toString(), this);
    lb[0]->setGeometry(10, 110, 150, 30);

    lb[1] = new QLabel(dt4.toString(), this);
    lb[1]->setGeometry(10, 150, 150, 30);

    if(QDate::isValid(2011, 6, 27))
    {
        qDebug("2013.6.27 true");
    }

    else
    {
        qDebug("2013.6.27 false");
    }

    QDate dt5 = QDate(2012, 4, 26);

    QString LongWeek = dt5.longDayName(dt5.dayOfWeek());
    QString LongMonth = dt5.longMonthName(dt5.month());
    QString strDateLong = QString("%1 %2").arg(LongWeek).arg(LongMonth);

    QString ShortWeek = dt5.shortDayName(dt5.dayOfWeek());
    QString ShortMonth = dt5.shortMonthName(dt5.month());
    QString strDateShort = QString("%1 %2").arg(ShortWeek).arg(ShortMonth);

    lb[2] = new QLabel(QString("Long : %1, Short : %2").arg(strDateLong).arg(strDateShort), this);
    lb[2]->setGeometry(10, 190, 250, 30);

    QDate dt6 = QDate(2022, 7, 26);

    lb[3] = new QLabel(dt6.toString(Qt::TextDate), this);
    lb[3]->setGeometry(10, 240, 250, 30);

    lb[4] = new QLabel(dt6.toString(Qt::ISODate), this);
    lb[4]->setGeometry(10, 270, 250, 30);

    lb[5] = new QLabel(dt6.toString(Qt::SystemLocaleDate), this);
    lb[5]->setGeometry(10, 300, 250, 30);

}

MainWindow::~MainWindow()
{
    delete ui;
}

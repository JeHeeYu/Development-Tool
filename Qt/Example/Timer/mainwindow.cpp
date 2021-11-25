#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


/*     Example 1    */
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Timer()));
    timer->start(1000);

/*     Example 2    */
    Timer();

}

MainWindow::~MainWindow()
{
    delete ui;
}


/*     Example 2    */
void MainWindow::Timer()
{
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");

    ui->timerLabel->setText(time_text);
}

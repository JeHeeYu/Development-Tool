#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   lb = new QLabel(this);

   image = QImage("Image/image.JPG");

   lb->setPixmap(QPixmap::fromImage(image));

   area = new QScrollArea(this);
   area->setWidget(lb);
   area->setBackgroundRole(QPalette::Dark);
   area->setGeometry(0, 0, image.width(), image.height());

}

MainWindow::~MainWindow()
{
    delete ui;
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString str1[3] = {"Computer", "Notebook", "Tablet"};

    int ypos = 30;

    for(int i = 0; i < 3; i++)
    {
        radio1[i] = new QRadioButton(str1[i], this);
        radio1[i]->setGeometry(10, ypos, 150, 30);

        ypos += 40;
    }

    QString str2[3] = {"In-vehicle", "Smart TV", "Mobile"};

    ypos = 30;

    for(int i = 0; i < 3; i++)
    {
        radio2[i] = new QRadioButton(str2[i], this);

        if(i == 2)
            radio2[i]->setChecked(true);

        radio2[i]->setGeometry(180, ypos, 150, 30);

        ypos += 40;
    }

    group1 = new QButtonGroup(this);
    group2 = new QButtonGroup(this);


    for(int i = 0; i < 3; i++)
    {
        group1->addButton(radio1[i]);
        group2->addButton(radio2[i]);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

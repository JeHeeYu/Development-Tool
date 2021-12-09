#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    edit[0] = new QLineEdit("", this);
    lb = new QLabel("QLineEdit Text : ", this);

    connect(edit[0], SIGNAL(textChanged(QString)), this, SLOT(textChanged(QString)));

    edit[0]->setGeometry(10, 30, 200, 40);
    lb->setGeometry(10, 80, 250, 30);

    int ypos = 120;

    for(int i = 1; i < 5; i++)
    {
        edit[i] = new QLineEdit("Hello World!", this);
        edit[i]->setGeometry(10, ypos, 200, 40);
        ypos += 50;
    }

    edit[1]->setEchoMode(QLineEdit::Normal);
    edit[2]->setEchoMode(QLineEdit::NoEcho);
    edit[3]->setEchoMode(QLineEdit::Password);
    edit[4]->setEchoMode(QLineEdit::PasswordEchoOnEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::textChanged(QString str)
{
    lb->setText(QString("QLineEdit Text : ").arg(str));
}

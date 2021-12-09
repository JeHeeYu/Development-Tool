#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for(int i = 0; i < 5; i++)
    {
        font[i] = new QFontComboBox(this);
    }

    font[0]->setFontFilters(QFontComboBox::AllFonts);
    font[1]->setFontFilters(QFontComboBox::ScalableFonts);
    font[2]->setFontFilters(QFontComboBox::NonScalableFonts);
    font[3]->setFontFilters(QFontComboBox::MonospacedFonts);
    font[4]->setFontFilters(QFontComboBox::ProportionalFonts);

    int ypos = 30;

    for(int i =0 ; i < 5; i++)
    {
        font[i]->setGeometry(10, ypos, 200, 30);
        ypos += 40;
    }

    lb = new QLabel("Hello World!", this);
    lb->setGeometry(10, ypos, 200, 30);

    connect(font[0], SIGNAL(currentIndexChanged(int)), this, SLOT(changedIndex(int)));
    connect(font[0], SIGNAL(currentFontChanged(QFont)), this, SLOT(changedFont(const QFont &)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changedIndex(int idx)
{
    qDebug("Font Index : %d", idx);
}

void MainWindow::changedFont(const QFont &f)
{
    lb->setFont(f.family());
}

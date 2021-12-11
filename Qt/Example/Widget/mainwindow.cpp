#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    edit = new QLineEdit("", this);
    edit->setGeometry(120, 20, 100, 30);
}

MainWindow::~MainWindow()
{
   delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QString img_full_name;

    QPainter painter(this);

    img_full_name = QString("Image/Image.jpg");

    QImage image(img_full_name);

    painter.drawPixmap(0, 0, QPixmap::fromImage(image.scaled(100, 100, Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));

    painter.end();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);

    qDebug("[Resize Event Call]");
    qDebug("width : %d, height : %d", this->width(), this->height());
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    qDebug("[Mouse Press] x, y : %d, %d", event->x(), event->y());
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    qDebug("[Mouse Release] x, y : %d, %d", event->x(), event->y());
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    qDebug("[Mouse Double Click] x, y : %d, %d", event->x(), event->y());
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    qDebug("[Mouse Move Event] x, y : %d, %d", event->x(), event->y());
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    Q_UNUSED(event);
    qDebug("Key Release Event");

    switch(event->key())
    {
        case Qt::Key_A:
        if(event->modifiers())
            qDebug("A");
        else
            qDebug("a");

        qDebug("%x", event->key());

        break;

    default:
        break;
    }
}
void MainWindow::focusInEvent(QFocusEvent *event)
{
    Q_UNUSED(event);
    qDebug("focusInEvent Event");
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    Q_UNUSED(event);
    qDebug("Key Release Event");
}

void MainWindow::focusOutEnent(QFocusEvent *event)
{
    Q_UNUSED(event);
    qDebug("focusOutEvent Event");
}

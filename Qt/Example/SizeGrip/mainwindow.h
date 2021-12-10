#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSizeGrip>
#include <QTextEdit>
#include <QBoxLayout>
#include <QSplitter>

class SubWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    SubWindow(QMainWindow *parent = nullptr) : QMainWindow(parent, Qt::SubWindow)
    {

    }

    QSize sizeHint() const
    {
        return QSize(20, 10);
    }
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H

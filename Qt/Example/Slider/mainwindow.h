#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSlider>
#include <QLabel>

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

    QSlider *slider[6];
    QLabel *lb[3];

private slots:
    void valueChanged1(int value);
    void valueChanged2(int value);
    void valueChanged3(int value);
};

#endif // MAINWINDOW_H

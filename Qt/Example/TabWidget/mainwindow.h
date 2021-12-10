#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QPushButton>

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

    QTabWidget *tab;
    QWidget *broswer, *user;
    QPushButton *btn[3];
    QString btn_str[3] = {"Button 1", "Button 2", "Button 3"};

private slots:
    void currentTab(int index);
};

#endif // MAINWINDOW_H

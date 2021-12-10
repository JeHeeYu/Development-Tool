#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QAction>

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

    QToolBar *toolbar;
    QAction *act[5];

private slots:
    void trigger1();
    void trigger2();
    void trigger3();
    void trigger4();
    void trigger5();

};

#endif // MAINWINDOW_H

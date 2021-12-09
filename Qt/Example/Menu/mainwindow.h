#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
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

    QMenu *menu[3];
    QMenuBar *menuBar;
    QLabel *lb;
    QAction *act[2];

private slots:
    void trigerMenu(QAction *act);
};

#endif // MAINWINDOW_H

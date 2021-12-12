#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBox>
#include <QHBoxLayout>
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

    QToolBox *box;
    QHBoxLayout *lay;
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;

private slots:
    void changedTab(int index);
};

#endif // MAINWINDOW_H


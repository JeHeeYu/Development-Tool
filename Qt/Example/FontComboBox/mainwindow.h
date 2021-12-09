#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFontComboBox>
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

    QFontComboBox *font[5];
    QLabel *lb;

private slots:
    void changedIndex(int idx);
    void changedFont(const QFont &f);
};

#endif // MAINWINDOW_H

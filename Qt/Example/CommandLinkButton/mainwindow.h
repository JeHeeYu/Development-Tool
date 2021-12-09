 #ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCommandLinkButton>

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

    QCommandLinkButton *cmmBtn;

private slots:
    void clickFunc();
};

#endif // MAINWINDOW_H

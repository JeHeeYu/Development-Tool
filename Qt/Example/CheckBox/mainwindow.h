 #ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QButtonGroup>

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

    QButtonGroup *chk_group[2];

    QCheckBox *exclusive[3];
    QCheckBox *non_exclusive[3];

private slots:
    void chkChanged();

};

#endif // MAINWINDOW_H

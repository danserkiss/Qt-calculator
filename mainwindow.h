#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void digit_pressed();
    void on_pushButton_dot_released();
    void on_pushButton_clear_clicked();
    void on_pushButton_plus_clicked();
    void on_pushButton_plusminus_clicked();
    void on_pushButton_percent_clicked();
    void on_pushButton_equals_released();
    void binary_operation_pressed();
};
#endif // MAINWINDOW_H

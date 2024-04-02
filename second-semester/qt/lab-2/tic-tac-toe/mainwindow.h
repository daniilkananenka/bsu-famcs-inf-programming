#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Field.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_cell00_clicked();
    void on_cell01_clicked();
    void on_cell02_clicked();
    void on_cell10_clicked();
    void on_cell11_clicked();
    void on_cell12_clicked();
    void on_cell20_clicked();
    void on_cell21_clicked();
    void on_cell22_clicked();

    void on_restartButton_clicked();

private:
    Ui::MainWindow *ui;
    Field* field;
};
#endif // MAINWINDOW_H

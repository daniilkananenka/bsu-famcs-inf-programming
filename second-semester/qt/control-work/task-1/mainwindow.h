#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include "setpassworddialog.h"
#include "logindialog.h"

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
    void on_actionSetUser_triggered();

    void on_checkUserButton_clicked();

private:
    Ui::MainWindow *ui;
    SetPasswordDialog* passwordDialog;
    LoginDialog* loginDialog;
    User user;
};
#endif // MAINWINDOW_H

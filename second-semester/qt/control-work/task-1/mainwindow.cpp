#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    passwordDialog = new SetPasswordDialog(&user);
    loginDialog = new LoginDialog(&user, ui->label);

    //connect(ui->menuButton, &QMenu::triggered, this, &MainWindow::on_setPasswordMenuButton_triggered);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSetUser_triggered() {
    passwordDialog->show();
}


void MainWindow::on_checkUserButton_clicked()
{
    loginDialog->show();
}


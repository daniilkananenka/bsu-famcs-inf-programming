#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Rational.h"
#include <sstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_resultButton_clicked()
{
    Rational a(ui->editFirstNum->text().toInt(), ui->editFirstDen->text().toInt());
    Rational b(ui->editSecondNum->text().toInt(), ui->editSecondDen->text().toInt());
    Rational result;

    QString act = ui->actionBox->currentText();

    if (act == "*") {
        result = a*b;
    }
    else if (act == "/") result = a / b;
    else {
        ui->resultLabel->setText("Error");
        return;
    }
    std::stringstream result_str;
    result_str << result;

    ui->resultLabel->setText((new QString)->fromStdString(result_str.str()));
}


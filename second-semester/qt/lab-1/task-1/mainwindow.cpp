#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Complex.h"
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
    Complex a(ui->editFirstReal->text().toDouble(), ui->editFirstImage->text().toDouble());
    Complex b(ui->editSecondReal->text().toDouble(), ui->editSecondReal->text().toDouble());
    Complex result;

    // Operation
    QString action = ui->actionSwitch->currentText();

    if (action == "+") result = a + b;
    else if (action == "-") result = a - b;
    else {
        ui->resultLabel->setText("Error");
        return;
    }
    std::stringstream result_str;
    result_str << result;
    //Отображение результата
    ui->resultLabel->setText((new QString)->fromStdString(result_str.str()));
}


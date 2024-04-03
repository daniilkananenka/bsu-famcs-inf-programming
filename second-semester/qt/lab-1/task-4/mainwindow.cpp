#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>
#include <algorithm>

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


void MainWindow::on_performButton_clicked()
{
    const std::string vector_string = ui->editVector->toPlainText().toStdString();
    std::istringstream vector_input_stream(vector_string);
    vector_input_stream >> storage;

    ui->resultText->setText("");
    QString action = ui->actionSwitch->currentText();
    if (action == "MAX"){
        ui->resultText->setText(QString::number(storage.FindMax()));
    } else if (action == "COUNT") {
        QString comparator_string = ui->compSwitch->currentText();
        int number = ui->editNumber->text().toInt();
        int result = 0;
        if (comparator_string == "=") {
            result = storage.Count([&](int a){return a == number;});
        } else if (comparator_string == "<") {
            result = storage.Count([&](int a){return a < number;});
        } else if (comparator_string == ">") {
            result = storage.Count([&](int a){return a > number;});
        }
        ui->resultText->setText(QString::number(result));
    } else if (action == "SORT") {
        QString comparator_string = ui->sortingSwitch->currentText();

        if (comparator_string == "High to Low") {
            storage.Sort(std::greater<int>());
        } else if (comparator_string == "Low to High") {
            storage.Sort(std::less<int>());
        }
        std::stringstream result;
        result << storage;
        ui->resultText->setText((new QString)->fromStdString(result.str()));
    } else {
        ui->resultText->setText("Error!");
    }
}


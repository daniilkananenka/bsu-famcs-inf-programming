#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    field = new Field(ui->resultLabel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// First row
void MainWindow::on_cell00_clicked(){field->ClickHandler(0,0,ui->cell00);}
void MainWindow::on_cell01_clicked(){field->ClickHandler(0,1,ui->cell01);}
void MainWindow::on_cell02_clicked(){field->ClickHandler(0,2,ui->cell02);}

// Second row
void MainWindow::on_cell10_clicked(){field->ClickHandler(1,0,ui->cell10);}
void MainWindow::on_cell11_clicked(){field->ClickHandler(1,1,ui->cell11);}
void MainWindow::on_cell12_clicked(){field->ClickHandler(1,2,ui->cell12);}

// Third row
void MainWindow::on_cell20_clicked(){field->ClickHandler(2,0,ui->cell20);}
void MainWindow::on_cell21_clicked(){field->ClickHandler(2,1,ui->cell21);}
void MainWindow::on_cell22_clicked(){field->ClickHandler(2,2,ui->cell22);}

void MainWindow::on_restartButton_clicked()
{
    field->RestartGame();
    ui->cell00->setText("");
    ui->cell01->setText("");
    ui->cell02->setText("");
    ui->cell10->setText("");
    ui->cell11->setText("");
    ui->cell12->setText("");
    ui->cell20->setText("");
    ui->cell21->setText("");
    ui->cell22->setText("");
}


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cell.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    optionsDialog = new OptionsDialog(&options, &field);

    field = Field(4, std::vector<QColor>(4, QColor(0,0,0,0)));
    playerField = Field(4, std::vector<QColor>(4, QColor(0,0,0,0)));
    GenerateGrid();
    ui->readyButton->setDisabled(true);

    connect(ui->actionNewGame, &QAction::triggered, this, &MainWindow::OnNewGameClick);
    connect(ui->readyButton, &QPushButton::clicked, this, &MainWindow::OnPlayerReadyClick);
    connect(optionsDialog, &OptionsDialog::OptionsConfiguredSignal,
            this, &MainWindow::OnGameStart);
}

void MainWindow::GenerateGrid() {
    while(ui->fieldGrid->layout()->count() > 0) {
        delete ui->fieldGrid->layout()->itemAt(0)->widget();
    }

    for (int row{}; row < options.Size(); ++row) {
        for (int col{}; col < options.Size(); ++col) {
            auto* cell = new Cell();
            if (isPlayerChoose) {
                cell->SetColor(QColor(0,0,0,0));
                cell->setDisabled(false);
            }
            if (!isPlayerChoose) {
                cell->SetColor(field[row][col]);
                cell->setDisabled(true);
            }
            cell->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            ui->fieldGrid->addWidget(cell, row, col);
        }

        ui->fieldGrid->setRowStretch(row, 1);
        ui->fieldGrid->setColumnStretch(row, 1);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnGameStart() {
    isPlayerChoose = false;
    ui->readyButton->setDisabled(false);
    GenerateGrid();
}

void MainWindow::OnPlayerReadyClick() {
    if(!isPlayerChoose) {
        isPlayerChoose = true;
        playerField = Field(options.Size(), std::vector<QColor>(options.Size(), QColor(0,0,0,0)));
        GenerateGrid();
        return;
    }

    isPlayerChoose = false;
    for (int i{}; i < ui->fieldGrid->layout()->count(); ++i) {
        ui->fieldGrid->layout()->itemAt(0)->widget()->setDisabled(true);
    }
    std::string message{};
    message = CheckWin() ? "WIN: " : "LOSE: ";
    message += "size - " + std::to_string(options.Size()) + ", color count - " +
               std::to_string(options.ColorCount());

    ui->textEdit->append((new QString)->fromStdString(message));
}

bool MainWindow::CheckWin() {
    for (int row{}; row < options.Size(); ++row) {
        for (int col{}; col < options.Size(); ++col) {
            auto* cell = dynamic_cast<Cell*>(ui->fieldGrid->itemAtPosition(row, col)->widget());
            if (field[row][col] != cell->Color()) {
                return false;
            }
        }
    }
    return true;
}

void MainWindow::OnNewGameClick() {
    ui->readyButton->setDisabled(true);
    optionsDialog->show();
}


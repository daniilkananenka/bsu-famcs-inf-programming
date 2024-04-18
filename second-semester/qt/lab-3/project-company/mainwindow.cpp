#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , projectService(new ProjectService())
{
    ui->setupUi(this);
    supervisorProjectsDialog = new SupervisorProjectsDialog(projectService);
    performerTasksDialog = new PerformerTasksDialog(projectService);
    projectPerformersDialog = new ProjectPerformersDialog(projectService);
    missedDeadlinePerformersDialog = new MissedDeadlinePerformersDialog(projectService);
    Connect();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete projectService;
}

void MainWindow::Connect() {
    connect(ui->openFileButton, &QPushButton::clicked, this, &MainWindow::onOpenFileClick);
    connect(ui->saveFileButton, &QPushButton::clicked, this, &MainWindow::onSaveFileCLick);
    connect(ui->addItemButton, &QPushButton::clicked, this, &MainWindow::onAddItemClick);
    connect(ui->supervisorProjectsButton, &QPushButton::clicked, this, &MainWindow::onSupervisorProjectsClick);
    connect(ui->performerTasksButton, &QPushButton::clicked, this, &MainWindow::onPerformerTasksClick);
    connect(ui->projectPerformersButton, &QPushButton::clicked, this, &MainWindow::onProjectPerformersClick);
    connect(ui->missedDeadlinePerformersButton, &QPushButton::clicked, this, &MainWindow::onMissedDeadlinePerformersClick);
}

void MainWindow::PrintProjects() {
    ui->output->setText((new QString)->fromStdString(projectService->ToString()));
}

void MainWindow::onOpenFileClick() {
    QString file_name = QFileDialog::getOpenFileName(0, "Open dialog", "", "*.txt");
    projectService->ReadFromFile(file_name.toStdString());
    PrintProjects();
}

void MainWindow::onSaveFileCLick() {
    QString file_name = QFileDialog::getOpenFileName(0, "Open dialog", "", "*.txt");
    projectService->PrintInFile(file_name.toStdString());
}

void MainWindow::onAddItemClick() {
    ProjectItem new_item;
    new_item.SetTitle(ui->editTitle->text().toStdString())
        .SetTask(ui->editTask->text().toStdString())
        .SetPerformer(ui->editPerformer->text().toStdString())
        .SetSupervisor(ui->editSupervisor->text().toStdString())
        .SetIssueDate(ui->editIssueDate->date())
        .SetDueDate(ui->editDueDate->date())
        .SetDeadline(ui->editDeadline->date());

    projectService->Add(new_item);
    PrintProjects();
}
void MainWindow::onSupervisorProjectsClick() {
    supervisorProjectsDialog->show();
}
void MainWindow::onPerformerTasksClick() {
    performerTasksDialog->show();
}
void MainWindow::onProjectPerformersClick() {
    projectPerformersDialog->show();
}
void MainWindow::onMissedDeadlinePerformersClick() {
    missedDeadlinePerformersDialog->show();
}


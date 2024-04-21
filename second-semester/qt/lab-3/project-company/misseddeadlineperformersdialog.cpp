#include "misseddeadlineperformersdialog.h"
#include "ui_misseddeadlineperformersdialog.h"

MissedDeadlinePerformersDialog::MissedDeadlinePerformersDialog(ProjectService* service, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MissedDeadlinePerformersDialog),
    projectService(service)
{
    ui->setupUi(this);
    Connect();
}

MissedDeadlinePerformersDialog::~MissedDeadlinePerformersDialog()
{
    delete ui;
}

void MissedDeadlinePerformersDialog::Connect() {
    connect(ui->searchButton, &QPushButton::clicked, this, &MissedDeadlinePerformersDialog::onSearchClick);
}

void MissedDeadlinePerformersDialog::onSearchClick() {
    ProjectVector items = projectService->Where([](const ProjectItem& item){
        return item.DueDate() < item.Deadline();
    });

    ProjectSequence sequance = std::make_pair(items.begin(), items.end());
    ui->output->setText((new QString)->fromStdString(ProjectService::ToString(sequance)));
}

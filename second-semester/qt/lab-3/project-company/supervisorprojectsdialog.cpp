#include "supervisorprojectsdialog.h"
#include "ui_supervisorprojectsdialog.h"

SupervisorProjectsDialog::SupervisorProjectsDialog(ProjectService* service, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SupervisorProjectsDialog),
    projectService(service)
{
    ui->setupUi(this);
    Connect();
}

SupervisorProjectsDialog::~SupervisorProjectsDialog()
{
    delete ui;
}

void SupervisorProjectsDialog::Connect() {
    connect(ui->searchButton, &QPushButton::clicked, this, &SupervisorProjectsDialog::onSearchClick);
}

void SupervisorProjectsDialog::onSearchClick() {
    std::string supervisor = ui->editSupervisor->text().toStdString();
    std::string result = ProjectService::ToString(projectService->FindAll([supervisor](const ProjectItem& item){
        return item.Supervisor() == supervisor;
    }, [](const ProjectItem& a, const ProjectItem& b) {
        return a.Supervisor() < b.Supervisor();
    }));

    ui->output->setText((new QString)->fromStdString(result));
}

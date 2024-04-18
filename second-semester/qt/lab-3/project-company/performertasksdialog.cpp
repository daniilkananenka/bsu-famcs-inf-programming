#include "performertasksdialog.h"
#include "ui_performertasksdialog.h"

PerformerTasksDialog::PerformerTasksDialog(ProjectService* service, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PerformerTasksDialog),
    projectService(service)
{
    ui->setupUi(this);
    Connect();
}

PerformerTasksDialog::~PerformerTasksDialog()
{
    delete ui;
}

void PerformerTasksDialog::Connect() {
    connect(ui->searchButton, &QPushButton::clicked, this, &PerformerTasksDialog::onSearchClick);
}

void PerformerTasksDialog::onSearchClick() {
    std::string performer = ui->editPerformer->text().toStdString();
    std::string result = ProjectService::ToString(projectService->FindAll([performer](const ProjectItem& item){
        return item.Performer() == performer;
    }, [](const ProjectItem& a, const ProjectItem& b) {
        return a.Performer() < b.Performer();
    }));

    ui->output->setText((new QString)->fromStdString(result));
}

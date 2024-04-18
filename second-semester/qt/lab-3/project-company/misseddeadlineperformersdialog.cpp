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
//    std::string performer = ui->editProject->text().toStdString();
//    std::string result = ProjectService::ToString(projectService->FindAll([performer](const ProjectItem& item){
//        return item.Performer() == performer;
//    }, [](const ProjectItem& a, const ProjectItem& b) {
//        return a.Performer() < b.Performer();
//    }));

//    ui->output->setText((new QString)->fromStdString(result));
}

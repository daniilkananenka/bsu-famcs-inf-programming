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
    std::string result{};
    auto [begin, end] = projectService->FindAll([supervisor](const ProjectItem& item){
        return item.Supervisor() == supervisor;
    }, [](const ProjectItem& a, const ProjectItem& b) {
        return a.Supervisor() < b.Supervisor();
    });

    std::set<std::string> projects;
    while (begin != end) {
        projects.emplace((*begin).Title());
        ++begin;
    }
    for (auto& i : projects) {
        result += i + "\n";
    }

    ui->output->setText((new QString)->fromStdString(result));
}

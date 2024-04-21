#include "projectperformersdialog.h"
#include "ui_projectperformersdialog.h"

ProjectPerformersDialog::ProjectPerformersDialog(ProjectService* service, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProjectPerformersDialog),
    projectService(service)
{
    ui->setupUi(this);
    Connect();
}

ProjectPerformersDialog::~ProjectPerformersDialog()
{
    delete ui;
}

void ProjectPerformersDialog::Connect() {
    connect(ui->searchButton, &QPushButton::clicked, this, &ProjectPerformersDialog::onSearchClick);
}

void ProjectPerformersDialog::onSearchClick() {
    std::string result{};
    std::string project = ui->editProject->text().toStdString();
    auto [begin, end] = projectService->FindSequence([project](const ProjectItem& item){
        return item.Title() == project;
    }, [](const ProjectItem& a, const ProjectItem& b) {
        return a.Title() < b.Title();
    });

    std::set<std::string> performers;
    while (begin != end) {
        performers.emplace((*begin).Performer());
        ++begin;
    }
    for (auto& i : performers) {
        result += i + "\n";
    }

    ui->output->setText((new QString)->fromStdString(result));
}

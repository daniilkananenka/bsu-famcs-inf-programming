#ifndef SUPERVISORPROJECTSDIALOG_H
#define SUPERVISORPROJECTSDIALOG_H

#include <QDialog>
#include <QString>
#include "projectservice.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class SupervisorProjectsDialog;
}
QT_END_NAMESPACE

class SupervisorProjectsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SupervisorProjectsDialog(ProjectService* service, QWidget *parent = nullptr);
    ~SupervisorProjectsDialog();

private slots:
    void onSearchClick();

private:
    Ui::SupervisorProjectsDialog *ui;
    ProjectService *projectService;

    void Connect();
};

#endif // SUPERVISORPROJECTSDIALOG_H

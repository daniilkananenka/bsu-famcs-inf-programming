#ifndef PERFORMERTASKSDIALOG_H
#define PERFORMERTASKSDIALOG_H

#include <QDialog>
#include <QString>
#include "projectservice.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class PerformerTasksDialog;
}
QT_END_NAMESPACE

class PerformerTasksDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PerformerTasksDialog(ProjectService* service, QWidget *parent = nullptr);
    ~PerformerTasksDialog();

private slots:
    void onSearchClick();

private:
    Ui::PerformerTasksDialog *ui;
    ProjectService *projectService;

    void Connect();
};

#endif // PERFORMERTASKSDIALOG_H

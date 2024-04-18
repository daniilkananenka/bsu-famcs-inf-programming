#ifndef PROJECTPERFORMERSDIALOG_H
#define PROJECTPERFORMERSDIALOG_H

#include <QDialog>
#include <QString>
#include "projectservice.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class ProjectPerformersDialog;
}
QT_END_NAMESPACE

class ProjectPerformersDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProjectPerformersDialog(ProjectService* service, QWidget *parent = nullptr);
    ~ProjectPerformersDialog();

private slots:
    void onSearchClick();

private:
    Ui::ProjectPerformersDialog *ui;
    ProjectService *projectService;

    void Connect();
};

#endif // PROJECTPERFORMERSDIALOG_H

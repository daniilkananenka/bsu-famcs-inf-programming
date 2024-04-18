#ifndef MISSEDDEADLINEPERFORMERSDIALOG_H
#define MISSEDDEADLINEPERFORMERSDIALOG_H

#include <QDialog>
#include <QString>
#include "projectservice.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MissedDeadlinePerformersDialog;
}
QT_END_NAMESPACE

class MissedDeadlinePerformersDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MissedDeadlinePerformersDialog(ProjectService* service, QWidget *parent = nullptr);
    ~MissedDeadlinePerformersDialog();

private slots:
    void onSearchClick();

private:
    Ui::MissedDeadlinePerformersDialog *ui;
    ProjectService *projectService;

    void Connect();
};

#endif // MISSEDDEADLINEPERFORMERSDIALOG_H

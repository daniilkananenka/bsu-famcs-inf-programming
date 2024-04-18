#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>

#include "projectservice.h"
#include "supervisorprojectsdialog.h"
#include "performertasksdialog.h"
#include "projectperformersdialog.h"
#include "misseddeadlineperformersdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onOpenFileClick();
    void onSaveFileCLick();
    void onAddItemClick();
    void onSupervisorProjectsClick();
    void onPerformerTasksClick();
    void onProjectPerformersClick();
    void onMissedDeadlinePerformersClick();

private:
    Ui::MainWindow *ui;
    ProjectService *projectService;

    // Dialogs
    SupervisorProjectsDialog *supervisorProjectsDialog;
    PerformerTasksDialog *performerTasksDialog;
    ProjectPerformersDialog *projectPerformersDialog;
    MissedDeadlinePerformersDialog *missedDeadlinePerformersDialog;

    void Connect();
    void PrintProjects();
};
#endif // MAINWINDOW_H

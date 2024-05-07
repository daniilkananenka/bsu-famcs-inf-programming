#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "options.h"
#include "optionsdialog.h"
#include "field.h"

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
    void OnNewGameClick();
    void OnGameStart();
    void OnPlayerReadyClick();

private:
    Ui::MainWindow *ui;
    Options options;
    OptionsDialog* optionsDialog;
    Field field;
    Field playerField;
    bool isPlayerChoose;

    void GenerateGrid();
    bool CheckWin();
};
#endif // MAINWINDOW_H

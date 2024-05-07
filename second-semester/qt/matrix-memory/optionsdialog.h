#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QDialog>
#include "options.h"
#include "field.h"

namespace Ui {
class OptionsDialog;
}

class OptionsDialog : public QDialog
{
    Q_OBJECT

public:
    OptionsDialog(Options*, Field*, QWidget *parent = nullptr);
    ~OptionsDialog();

signals:
    void OptionsConfiguredSignal();

private slots:
    void OnGenerateClick();

private:
    Ui::OptionsDialog *ui;
    Options* options;
    Field* field;

    void GenerateField();
};

#endif // OPTIONSDIALOG_H

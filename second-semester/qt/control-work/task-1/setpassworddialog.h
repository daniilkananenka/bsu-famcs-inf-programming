#ifndef SETPASSWORDDIALOG_H
#define SETPASSWORDDIALOG_H

#include <QDialog>
#include <string>
#include "user.h"

namespace Ui {
class SetPasswordDialog;
}

class SetPasswordDialog : public QDialog
{
    Q_OBJECT

public:
    SetPasswordDialog(User* user_, QWidget *parent = nullptr);
    ~SetPasswordDialog();

private slots:
    void on_closeButton_clicked();

    void on_setUserButton_clicked();

private:
    Ui::SetPasswordDialog *ui;
    User* user;
};

#endif // SETPASSWORDDIALOG_H

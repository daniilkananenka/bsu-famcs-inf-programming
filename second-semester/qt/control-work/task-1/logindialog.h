#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "user.h"
#include <QLabel>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    LoginDialog(User*, QLabel*, QWidget *parent = nullptr);
    ~LoginDialog();

private slots:
    void on_closeButton_clicked();

    void on_checkButton_clicked();

private:
    Ui::LoginDialog *ui;
    User* user;
    QLabel* status_label;
};

#endif // LOGINDIALOG_H

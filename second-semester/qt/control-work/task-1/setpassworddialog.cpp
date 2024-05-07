#include "setpassworddialog.h"
#include "ui_setpassworddialog.h"

SetPasswordDialog::SetPasswordDialog(User* user_, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetPasswordDialog),
    user(user_)
{
    ui->setupUi(this);
}

SetPasswordDialog::~SetPasswordDialog()
{
    delete ui;
}

void SetPasswordDialog::on_closeButton_clicked()
{
    this->close();
}


void SetPasswordDialog::on_setUserButton_clicked()
{
    user->name = ui->editUsername->text().toStdString();
    user->password =ui->editPassword->text().toStdString();
    this->close();
}


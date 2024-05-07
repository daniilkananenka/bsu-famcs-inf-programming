#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(User* user_, QLabel* status_label_, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog),
    user(user_),
    status_label(status_label_)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_closeButton_clicked()
{
    this->close();
}


void LoginDialog::on_checkButton_clicked()
{
    if (user->name == ui->editUsername->text().toStdString() &&
        user->password == ui->editPassword->text().toStdString()) {
        status_label->clear();
        std::string user_info = "Name: " + user->name + "; Pass: " + user->password;
        status_label->setText((new QString)->fromStdString(user_info));
        this->close();
    }
}


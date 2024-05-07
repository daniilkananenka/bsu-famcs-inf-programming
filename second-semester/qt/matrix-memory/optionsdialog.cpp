#include "optionsdialog.h"
#include "ui_optionsdialog.h"
#include <random>

OptionsDialog::OptionsDialog(Options* options_,
                             Field* field_,
                             QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionsDialog),
    options(options_),
    field(field_)
{
    ui->setupUi(this);
    connect(ui->generateButton, &QPushButton::clicked, this, &OptionsDialog::OnGenerateClick);
}

OptionsDialog::~OptionsDialog()
{
    delete ui;
}

void OptionsDialog::OnGenerateClick() {
    options->SetSize(ui->editSize->text().toInt());
    options->SetColorCount(ui->colorCountSlider->value());
    GenerateField();

    emit OptionsConfiguredSignal();
    this->close();
}

void OptionsDialog::GenerateField() {
    srand(time(NULL));

    field->clear();
    *field = Field(options->Size(), std::vector<QColor>(options->Size(), QColor(0,0,0,0)));

    for (int row{}; row < options->Size(); ++row) {
        for (int col{}; col < options->Size(); ++col) {
            field->at(row)[col] = AVAILABLE_COLORS[std::rand() % options->ColorCount()];
        }
    }
}

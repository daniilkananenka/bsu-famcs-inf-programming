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
    if (options->Size() < 3) {
        options->SetSize(3);
        ui->editSize->setText("3");
    }
    options->SetColorCount(ui->colorCountSlider->value());
    options->SetLevel(ui->levelSlider->value());
    GenerateField();

    emit OptionsConfiguredSignal();
    this->close();
}

void OptionsDialog::makeLastStrOfVec(std::vector<std::vector<QColor>>& res, int temp_color, std::vector<QColor> AVAILABLE_COLORS, int color_count, int field_size){
    for (int temp = 0; temp < field_size; temp++){
        if (temp_color == color_count) temp_color = 0;
        res[field_size-1][temp] = AVAILABLE_COLORS[temp_color];
        temp_color++;
    }
}

std::vector<std::vector<QColor>> OptionsDialog::GenerateColors(int field_size, int color_count, int level){
    std::vector<std::vector<QColor>> resault_vec(field_size, std::vector<QColor>(field_size));
    int temp_color{};
    int board_for = field_size;
    if (field_size < color_count) board_for--;

    switch (level) {
    case 1: {
        for (int i = 0; i < board_for; i++){
            for (int j = 0; j < field_size; j++){
                resault_vec[i][j] = AVAILABLE_COLORS[temp_color];
            }
            temp_color++;
            if (temp_color == color_count) temp_color = 0;
        }
        // если цветов больше чем рядов
        // заполняем последнюю строку оставшимеся цветами
        if (board_for == field_size - 1) makeLastStrOfVec(resault_vec, temp_color, AVAILABLE_COLORS, color_count, field_size);
        break;
    }

    case 2: {
        int color_board{1};
        for (int i = 0; i < board_for; i++){
            for (int j = 0; j < field_size; j++){
                if (j < color_board) temp_color = j;
                else temp_color = color_board - 1;
                resault_vec[i][j] = AVAILABLE_COLORS[temp_color];
            }  // change board
            color_board++;
            if (color_board == color_count + 1) color_board = 1;
        }
        // если цветов больше чем рядов
        // заполняем последнюю строку оставшимеся цветами
        if (board_for == field_size - 1){
            temp_color = color_board - 1;
            makeLastStrOfVec(resault_vec, temp_color, AVAILABLE_COLORS, color_count, field_size);
        }
        break;
    }

    case 3: {
        bool flag_to_revers{1};
        for (int i = 0; i < field_size; i++){
            for (int j = 0; j < field_size; j++){
                if (flag_to_revers) {
                    if (temp_color == color_count) temp_color = 0;
                    resault_vec[i][j] = AVAILABLE_COLORS[temp_color];
                    temp_color++;
                } else {
                    if (temp_color == -1) temp_color = color_count - 1;
                    resault_vec[i][j] = AVAILABLE_COLORS[temp_color];
                    temp_color--;
                }
            }
            flag_to_revers = not flag_to_revers;
        }
        break;
    }

    }
    return resault_vec;
}



void OptionsDialog::GenerateField() {
    srand(time(NULL));

    field->clear();
    *field = GenerateColors(options->Size(), options->ColorCount(), options->Level());
}

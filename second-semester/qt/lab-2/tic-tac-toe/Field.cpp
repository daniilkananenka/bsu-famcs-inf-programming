#include "Field.h"

void Field::ApplyStepToButton(QPushButton* button){
    button->setText((currentStep == Player::CROSS) ? "X" : "O");
}
void Field::ChangePlayer() {
    currentStep = (currentStep == Player::CROSS) ? Player::CIRCLE : Player::CROSS;
}
void Field::StopGame(Player winner) {
    switch (winner) {
    case Player::CROSS:
        resultLabel->setText("X is winner!");
        break;
    case Player::CIRCLE:
        resultLabel->setText("O is winner!");
        break;
    case Player::NONE:
        resultLabel->setText("Draw!");
        break;
    }
    isRunning = false;
}

Field::Field(QLabel* resultLabel) :
    data(FieldData(3, std::vector<Player>(3, Player::NONE))),
    currentStep(Player::CROSS),
    resultLabel(resultLabel),
    stepCount(0),
    isRunning(true) {}

void Field::RestartGame() {
    data = FieldData(3, std::vector<Player>(3, Player::NONE));
    currentStep = Player::CROSS;
    stepCount = 0;
    isRunning = true;
    resultLabel->setText("");
}
void Field::ClickHandler(size_t row, size_t col, QPushButton* button) {
    if (!isRunning) {
        return;
    }
    ++stepCount;
    Player& cell = this->operator()(row, col);
    if (cell != Player::NONE) {
        return;
    }

    cell = currentStep;
    ApplyStepToButton(button);
    if (winChecker.Check(*this)) {
        StopGame(currentStep);
        return;
    }
    if (stepCount == MAX_STEP_COUNT) {
        StopGame(Player::NONE);
        return;
    }
    ChangePlayer();
}
Player& Field::operator()(size_t i, size_t j) {
    return data[i][j];
}

const Player& Field::operator()(size_t i, size_t j) const {
    return data[i][j];
}

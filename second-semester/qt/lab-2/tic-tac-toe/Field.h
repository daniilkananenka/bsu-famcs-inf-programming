#ifndef FIELD_H
#define FIELD_H

#include <cstddef>
#include <vector>
#include <QPushButton>
#include <QLabel>

constexpr size_t MAX_STEP_COUNT = 9;

enum class Player {
    CROSS,
    CIRCLE,
    NONE
};

using FieldData = std::vector<std::vector<Player>>;
class WinChecker;

class Field {
private:
    class WinChecker {
    private:
        bool CheckRow(size_t row, const Field& field);
        bool CheckCol(size_t col, const Field& field);
        bool CheckMainDiag(const Field& field);
        bool CheckSideDiag(const Field& field);
    public:
        bool Check(const Field& field);
    };

    WinChecker winChecker;
    FieldData data;
    Player currentStep;
    QLabel* resultLabel;

    size_t stepCount;
    bool isRunning;

    void ApplyStepToButton(QPushButton* button);
    void ChangePlayer();
    void StopGame(Player winner);

public:
    Field(QLabel* resultLabel);
    void ClickHandler(size_t row, size_t col, QPushButton* button);
    void RestartGame();
    Player& operator()(size_t i, size_t j);
    const Player& operator()(size_t i, size_t j) const;
};



#endif // FIELD_H

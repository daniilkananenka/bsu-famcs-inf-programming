#include "Field.h"

bool Field::WinChecker::CheckRow(size_t row, const Field& field) {
    return field(row, 0) != Player::NONE && field(row, 0) == field(row, 1) && field(row, 0) == field(row, 2);
}
bool Field::WinChecker::CheckCol(size_t col, const Field& field) {
    return field(0, col) != Player::NONE && field(0, col) == field(1, col) && field(0, col) == field(2, col);
}
bool Field::WinChecker::CheckMainDiag(const Field& field) {
    return field(0, 0) != Player::NONE && field(0, 0) == field(1, 1) && field(0, 0) == field(2, 2);
}
bool Field::WinChecker::CheckSideDiag(const Field& field) {
    return field(0, 2) != Player::NONE && field(0, 2) == field(1, 1) && field(0, 2) == field(2, 0);
}
bool Field::WinChecker::Check(const Field& field) {
    bool result = false;
    for (int i = 0; i < 3; ++i) {
        result = result || CheckRow(i, field);
        result = result || CheckCol(i, field);
    }
    result = result || CheckMainDiag(field) || CheckSideDiag(field);
    return result;
}

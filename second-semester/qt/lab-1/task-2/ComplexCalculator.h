#ifndef COMPLEXCALCULATOR_H
#define COMPLEXCALCULATOR_H

#include <QMainWindow>
#include "ComplexNumber.h"
class QLineEdit;
class QComboBox;
class QLabel;
class QPushButton;
class QWidget;


class ComplexCalculator : public QMainWindow {
    Q_OBJECT
private:
    QWidget* centralWidget;
    QLineEdit* pleFirstReal;
    QLineEdit* pleFirstImage;
    QLineEdit* pleSecondReal;
    QLineEdit* pleSecondImage;

    QComboBox* pcbAction;
    QPushButton* ppbCalc;
    QLabel* plResult;
public:
    ComplexCalculator(QWidget* pwgt = 0);
    ComplexNumber sum(ComplexNumber& a, ComplexNumber& b);
    ComplexNumber difference(ComplexNumber& a, ComplexNumber& b);

public slots:
    void slotCalcClicked();
};
#endif // COMPLEXCALCULATOR_H

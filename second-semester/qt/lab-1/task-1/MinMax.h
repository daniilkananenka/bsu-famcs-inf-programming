#ifndef MINMAX_H
#define MINMAX_H

#include <QMainWindow>
class QLineEdit;
class QComboBox;
class QLabel;
class QPushButton;
class QWidget;


class MinMax : public QMainWindow {
    Q_OBJECT
private:
    QWidget *centralWidget;
    QLineEdit* pleFirstNum;
    QLineEdit* pleSecondNum;
    QLineEdit* pleThirdNum;
    QComboBox* pcbAction;
    QPushButton* ppbGet;
    QLabel* plResult;
public:
    MinMax(QWidget* pwgt = 0);
    double getMin(double a, double b, double c);
    double getMax(double a, double b, double c);

public slots:
    void slotGetClicked();
};

#endif // MINMAX_H

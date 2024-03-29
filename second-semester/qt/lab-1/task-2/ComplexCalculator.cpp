#include <QtWidgets>
#include "ComplexCalculator.h"
#include <sstream>

ComplexCalculator::ComplexCalculator(QWidget* pwgt) :
    QMainWindow(pwgt)
{
    // Line edit
    pleFirstReal = new QLineEdit();
    pleFirstReal->setMaximumWidth(300);
    pleFirstImage = new QLineEdit();
    pleFirstImage->setMaximumWidth(300);

    pleSecondReal = new QLineEdit();
    pleSecondReal->setMaximumWidth(300);
    pleSecondImage = new QLineEdit();
    pleSecondImage->setMaximumWidth(300);

    // Combo box
    pcbAction = new QComboBox();
    pcbAction->setMaximumWidth(300);
    pcbAction->addItems(QStringList() << "Sum" << "Dif");

    // Push buttons
    ppbCalc = new QPushButton("Get");
    ppbCalc->setMaximumWidth(300);
    connect(ppbCalc, SIGNAL(clicked(bool)),
            SLOT(slotCalcClicked()));

    // Label
    plResult = new QLabel("Not specified");
    plResult->setMaximumWidth(300);

    // Main widget
    QVBoxLayout* pvbxLayout = new QVBoxLayout(this);
    pvbxLayout->addWidget(new QLabel("A Real"));
    pvbxLayout->addWidget(pleFirstReal);
    pvbxLayout->addWidget(new QLabel("A Image"));
    pvbxLayout->addWidget(pleFirstImage);
    pvbxLayout->addWidget(new QLabel("B Real"));
    pvbxLayout->addWidget(pleSecondReal);
    pvbxLayout->addWidget(new QLabel("B Image"));
    pvbxLayout->addWidget(pleSecondImage);


    pvbxLayout->addWidget(pcbAction);
    pvbxLayout->addWidget(ppbCalc);
    pvbxLayout->addWidget(plResult);
    pvbxLayout->setContentsMargins(10, 10, 10,
                                   10);
    centralWidget = new QWidget();
    centralWidget->setLayout(pvbxLayout);
    setCentralWidget(centralWidget);
}

ComplexNumber ComplexCalculator::sum(ComplexNumber& a, ComplexNumber& b) {
    return a + b;
}

ComplexNumber ComplexCalculator::difference(ComplexNumber& a, ComplexNumber& b) {
    return a - b;
}

void ComplexCalculator::slotCalcClicked()
{
    ComplexNumber a(pleFirstReal->text().toDouble(), pleFirstImage->text().toDouble());
    ComplexNumber b(pleSecondReal->text().toDouble(), pleSecondImage->text().toDouble());
    ComplexNumber result;

    // Operation
    QString act = pcbAction->currentText();

    if (act == "Sum") result = sum(a, b);
    else if (act == "Dif") result = difference(a, b);
    else {
        plResult->setText("Error");
        return;
    }
    std::stringstream result_str;
    result_str << result;
    //Отображение результата
    plResult->setText((new QString)->fromStdString(result_str.str()));
}

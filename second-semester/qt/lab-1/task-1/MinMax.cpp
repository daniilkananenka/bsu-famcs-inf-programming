#include "MinMax.h"
#include <QtWidgets>

MinMax::MinMax(QWidget* pwgt) :
    QMainWindow(pwgt)
{
    // Line edit
    pleFirstNum = new QLineEdit();
    pleFirstNum->setMaximumWidth(200);
    pleSecondNum = new QLineEdit();
    pleSecondNum->setMaximumWidth(200);
    pleThirdNum = new QLineEdit();
    pleThirdNum->setMaximumWidth(200);

    // Combo box
    pcbAction = new QComboBox();
    pcbAction->setMaximumWidth(200);
    pcbAction->addItems(QStringList() << "Min" << "Max");

    // Push buttons
    ppbGet = new QPushButton("Get");
    ppbGet->setMaximumWidth(200);
    connect(ppbGet, SIGNAL(clicked(bool)),
            SLOT(slotGetClicked()));

    // Label
    plResult = new QLabel("Not specified");
    plResult->setMaximumWidth(200);

    // Main widget
    QVBoxLayout* pvbxLayout = new QVBoxLayout(this);
    pvbxLayout->addWidget(pleFirstNum);
    pvbxLayout->addWidget(pleSecondNum);
    pvbxLayout->addWidget(pleThirdNum);


    pvbxLayout->addWidget(pcbAction);
    pvbxLayout->addWidget(ppbGet);
    pvbxLayout->addWidget(plResult);
    pvbxLayout->setContentsMargins(10, 10, 10,
                                   10);
    centralWidget = new QWidget();
    centralWidget->setLayout(pvbxLayout);
    setCentralWidget(centralWidget);
}

double MinMax::getMin(double a, double b, double c) {
    return std::min(a, std::min(b, c));
}

double MinMax::getMax(double a, double b, double c) {
    return std::max(a, std::max(b, c));
}

void MinMax::slotGetClicked()
{
    double a = pleFirstNum->text().toDouble();
    double b = pleSecondNum->text().toDouble();
    double c = pleThirdNum->text().toDouble();
    double result = 0;

    // Operation
    QString act = pcbAction->currentText();

    if (act == "Min") result = getMin(a, b, c);
    else if (act == "Max") result = getMax(a, b, c);
    else {
        plResult->setText("Error");
        return;
    }
    //Отображение результата
    plResult->setText((new QString)->setNum(result));
}

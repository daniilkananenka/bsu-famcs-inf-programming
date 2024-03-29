#include <QtWidgets>
#include "ComplexCalculator.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    ComplexCalculator complexCalculator;
    complexCalculator.setWindowTitle("Complex Calculator");
    complexCalculator.resize(300, 300);
    complexCalculator.show();

    return app.exec();
}

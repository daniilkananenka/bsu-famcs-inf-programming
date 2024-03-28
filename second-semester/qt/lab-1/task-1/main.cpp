#include <QtWidgets>
#include "MinMax.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    MinMax minMax;
    minMax.setWindowTitle("MinMax");
    minMax.resize(300, 300);
    minMax.show();

    return app.exec();
}

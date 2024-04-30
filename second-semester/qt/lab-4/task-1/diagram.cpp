#include "diagram.h"

Diagram::Diagram(QWidget* parent) : QWidget(parent)
{
    pen = new QPen();
}

std::istream& operator>>(std::istream& in, Diagram& diagram) {
    diagram.points.clear();
    int height{};
    diagram.max_height = 0;
    while (in >> height) {
        diagram.points.push_back(height);
        diagram.max_height = std::max(diagram.max_height, height);
    }
    diagram.update();
    return in;
}

void Diagram::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.begin(this);

    // SETTING UP
    pen->setColor(Qt::red);
    pen->setWidth(10);
    painter.setPen(*pen);

    // RENDERING
    double diagram_width = this->width();
    double diagram_height = this->height();
    double interval = diagram_width / (points.size() + 1);
    double position_x = interval;
    for (auto i : points) {
        double height = (static_cast<double>(i) / max_height) * (diagram_height - 40);
        painter.drawLine(position_x, diagram_height - height, position_x, diagram_height);
        position_x += interval;
    }

    pen->setColor(Qt::black);
    pen->setWidth(3);
    painter.setPen(*pen);
    position_x = interval - 10;
    for (auto i : points) {
        double height = (static_cast<double>(i) / max_height) * (diagram_height - 40);
        painter.drawText(position_x, diagram_height - height - 20, (new QString())->fromStdString(std::to_string(i)));
        position_x += interval;
    }

    painter.end();
}

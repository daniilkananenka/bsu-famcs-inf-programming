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
    double diagram_width = this->height();
    double diagram_height = this->width();
    double interval = diagram_width / (points.size() + 1);
    double position_x = interval;
    for (auto i : points) {
        double height = (static_cast<double>(i) / max_height) * (diagram_height - 40);
        painter.drawLine(height, position_x, 0, position_x);
        position_x += interval;
    }

    painter.end();
}


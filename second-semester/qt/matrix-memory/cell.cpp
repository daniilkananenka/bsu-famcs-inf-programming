#include "cell.h"

Cell::Cell()
{
    connect(this, &Cell::QPushButton::clicked, this, &Cell::OnColorChangeClick);
}

void Cell::OnColorChangeClick() {
    color = QColorDialog::getColor();
    this->update();
}

void Cell::paintEvent(QPaintEvent* event) {
    //QPushButton::paintEvent(event);
    double cell_width = this->width();
    double cell_height = this->height();
    double border_width = 4;

    QPainter painter(this);
    auto pen = QPen();
    pen.setColor(Qt::black);
    pen.setWidth(border_width);
    painter.setPen(pen);
    painter.drawRect(0,0,cell_width,cell_height);
    painter.fillRect(border_width/2,border_width/2,
                     cell_width-border_width,cell_height-border_width,
                     color);
    painter.end();
}

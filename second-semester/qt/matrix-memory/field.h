#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include <QColor>

using Field = std::vector<std::vector<QColor>>;
const std::vector<QColor> AVAILABLE_COLORS = {
    QColor(Qt::red),
    QColor(Qt::blue),
    QColor(Qt::yellow),
    QColor(Qt::green),
    QColor(Qt::white)
};
#endif // FIELD_H

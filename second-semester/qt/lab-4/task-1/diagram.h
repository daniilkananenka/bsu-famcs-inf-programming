#ifndef DIAGRAM_H
#define DIAGRAM_H

#include <QWidget>
#include <QPen>
#include <QColor>
#include <QPainter>
#include <QPoint>
#include <iostream>
#include <vector>

class Diagram : public QWidget
{
    Q_OBJECT
public:
    Diagram(QWidget* parent = nullptr);

    friend std::istream& operator>>(std::istream&, Diagram&);

protected:
    void paintEvent(QPaintEvent*);

private:
    std::vector<int> points;
    int max_height;
    QPen* pen;
};

#endif // DIAGRAM_H

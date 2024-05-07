#ifndef CELL_H
#define CELL_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QColorDialog>
#include <QPainter>

class Cell : public QPushButton
{
    Q_OBJECT
public:
    Cell();

    void SetColor(QColor value) {color=value;}
    QColor Color() const {return color;}

private slots:
    void OnColorChangeClick();

protected:
    void paintEvent(QPaintEvent*);
private:
    QColor color{0,0,0,0};
};

#endif // CELL_H

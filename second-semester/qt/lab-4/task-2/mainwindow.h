#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPen>
#include <QPainter>
#include <QPoint>
#include <QTimer>
#include <cmath>
#include <math.h>
#include <QPainterPath>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void timerSlot();

protected:
    void paintEvent(QPaintEvent*);
    void drawWater(QPainter&);
    void drawShip(QPainter&);
    void drawFlag(QPainter&);

private:
    Ui::MainWindow *ui;
    QPen* pen;
    QTimer* timer;
    int timer_delay{30};

    double water_interval{0};
    double flag_y{};
    bool flagUp{false};
};
#endif // MAINWINDOW_H

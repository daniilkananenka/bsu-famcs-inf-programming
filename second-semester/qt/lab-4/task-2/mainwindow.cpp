#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer();
    timer->setInterval(timer_delay);
    pen = new QPen();
    flag_y = this->height() / 2 - 200;

    connect(timer, &QTimer::timeout, this, &MainWindow::timerSlot);
    timer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerSlot() {
    this->update();
}

void MainWindow::drawWater(QPainter& painter) {
    int win_width = this->width();
    int win_height = this->height();

    pen->setColor(QColor(30, 144, 255));
    pen->setWidth(10);
    if (water_interval >= M_PI * 2) {
        water_interval = 0;
    } else {
        water_interval += (M_PI * 2) / 20;
    }
    QPainterPath path;
    int water_height = win_height / 3 * 2;
    int water_width = 40;
    path.moveTo(QPointF(0, std::sin(water_interval) * 20 + water_height));
    for (double i{}; i <= win_width; ++i){
        path.lineTo(QPointF(i, std::sin(i / water_width + water_interval) * 20 + water_height));
    }
    path.lineTo(QPointF(win_width, win_height));
    path.lineTo(QPointF(0, win_height));
    path.lineTo(QPointF(0, std::sin(water_interval) * 20 + water_height));
    painter.drawPath(path);
    painter.fillPath(path, QBrush(QColor(30, 144, 255)));
}

void MainWindow::drawShip(QPainter& painter) {
    pen->setColor(QColor(139, 69, 19));
    pen->setWidth(10);
    painter.setPen(*pen);
    int win_width = this->width();
    int win_height = this->height();
    QPainterPath path;
    double ship_width = win_width / 2;
    double ship_height = win_height / 2 + 50;
    painter.drawLine(ship_width, ship_height, ship_width, ship_height - 200);
    drawFlag(painter);
    double radius = 200;
    path.moveTo(QPointF(ship_width - radius, ship_height));
    for (double i{0}; i <= ship_width + radius; ++i){
        path.lineTo(QPointF(i, std::sqrt(radius * radius - (i- ship_width) * (i - ship_width)) + ship_height));
    }
    path.lineTo(QPointF(ship_width - radius, ship_height));
    painter.setClipPath(path, Qt::IntersectClip);
    painter.drawPath(path);
    painter.fillPath(path, QBrush(QColor(139, 69, 19)));
}

void MainWindow::drawFlag(QPainter& painter) {
    pen->setColor(Qt::red);
    pen->setWidth(10);
    painter.setPen(*pen);
    int win_width = this->width();
    int win_height = this->height();

    double flag_max_y = win_height / 2 - 150;
    double flag_x = win_width / 2;

    if (flagUp) {
        flag_y -= 5;
        if (flag_y <= flag_max_y) {
            flag_y = flag_max_y;
            flagUp = false;
        }
    } else {
        flag_y += 5;
        if (flag_y >= win_height / 2 - 20) {
            flag_y = win_height / 2  - 20;
            flagUp = true;
        }
    }
    painter.drawRect(flag_x, flag_y, 60, 50);
    painter.fillRect(flag_x, flag_y, 60, 50, QColor(Qt::red));
}

void MainWindow::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.begin(this);

    drawWater(painter);
    drawShip(painter);


    painter.end();
}


#include "ball.hpp"

Ball::Ball(QGraphicsView *view, int size) {
    //create ball
    this->setRect(0, 0, size, size);
    this->size = size;

    //connect timer to function move
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), SLOT(move()));

    //start timer
    timer->start(10);

    //init direction
    moveX = 1;
    moveY = 1;

    sizeView = view->size();

    //change color
    this->setBrush(Qt::red);
}

void Ball::move() {
    this->setPos(this->x() + 2 * moveX, this->y() + 2 * moveY);
    bounce();
}

void Ball::bounce() {
    if(this->x() < 0 || this->x() > sizeView.width() - this->size)
        moveX *= -1;
    if(this->y() < 0 || this->y() > sizeView.height() - this->size)
        moveY *= -1;
}

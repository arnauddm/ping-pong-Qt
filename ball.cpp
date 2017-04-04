#include "ball.hpp"

#include <QDebug>

Ball::Ball(const unsigned int _x, const unsigned _y, const unsigned int _w, const unsigned int _h)
{
    width = _w;
    height = _h;

    setRect(_x, _y, width, height);
    setBrush(Qt::black);
}

void Ball::setX(const unsigned int pos) {
    setPosition(pos, this->pos().y());
}

void Ball::setY(const unsigned int pos) {
    setPosition(this->pos().y(), pos);
}

void Ball::setPosition(const unsigned int posX, const unsigned int posY) {
    setRect(posX, posY, width, height);
    qDebug() << pos();
}

void Ball::setPosition(QPoint pos) {
    setRect(pos.x(), pos.y(), width, height);
}

unsigned int Ball::getX(void) {
    return pos().x();
}

unsigned int Ball::getY(void) {
    return pos().y();
}

unsigned int Ball::getWidth(void) {
    return width;
}

unsigned int Ball::getHeight(void) {
    return height;
}

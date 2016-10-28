#include "paddle.hpp"

Paddle::Paddle(int x,
               int y,
               int w,
               int h) {
    //create paddle
    this->setRect(x, y, w, h);

    //set focusable, "select this on screen"
    this->setFlag(QGraphicsRectItem::ItemIsFocusable);
    this->setFocus();

    //change color
    this->setBrush(Qt::black);
}

void Paddle::keyPressEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_Up)
        this->setPos(x(), y() - 15);
    else if(event->key() == Qt::Key_Down)
        this->setPos(x(), y() + 15);
}

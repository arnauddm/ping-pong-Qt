#include "paddle.hpp"

Paddle::Paddle(int x,
               int y,
               int w,
               int h,
               bool yourPaddle) {
    //create paddle
    this->setRect(x, y, w, h);

    //init var
    this->yourPaddle = yourPaddle;

    //set focusable, "select this on screen" if this is your paddle
    if(this->yourPaddle) {
        this->setFlag(QGraphicsRectItem::ItemIsFocusable);
        this->setFocus();
    }

    //change color
    if(this->yourPaddle)
        this->setBrush(Qt::red);
    else
        this->setBrush(Qt::black);
}

void Paddle::keyPressEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_Up && this->yourPaddle)
        this->setPos(x(), y() - 15);
    else if(event->key() == Qt::Key_Down && this->yourPaddle)
        this->setPos(x(), y() + 15);
}

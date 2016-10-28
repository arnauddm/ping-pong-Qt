#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QBrush>

class Paddle : public QGraphicsRectItem {
public:
    Paddle(int x, int y, int w, int h, bool yourPaddle);

private:
    bool yourPaddle;

signals:

public slots:

protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // PADDLE_HPP

#ifndef BALL_HPP
#define BALL_HPP

#include <QObject>
#include <QGraphicsEllipseItem>
#include <QTimer>
#include <QGraphicsView>
#include <QBrush>

class Ball : public QObject, public QGraphicsEllipseItem {
    Q_OBJECT
public:
    Ball(QGraphicsView *view, int size);

private:
    int moveX, moveY, size;
    QSize sizeView;

    void bounce();

signals:

private slots:
    void move();
};

#endif // BALL_HPP

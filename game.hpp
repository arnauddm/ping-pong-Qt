#ifndef GAME_HPP
#define GAME_HPP

#include "ball.hpp"
#include "paddle.hpp"

#include <QGraphicsView>
#include <QGraphicsScene>

class Game : public QGraphicsView
{
public:
    Game();

private:
    Ball *ball;
    Paddle *leftPaddle;
    Paddle *rightPaddle;
    QGraphicsScene *scene;

signals:

public slots:
};

#endif // GAME_HPP

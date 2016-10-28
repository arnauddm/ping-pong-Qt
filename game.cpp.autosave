#include "game.hpp"

Game::Game()
{
    //create scene & view
    scene = new QGraphicsScene();

    //setting scene & view
    scene->setBackgroundBrush(Qt::white);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setFixedSize(800, 600);
    scene->setSceneRect(0, 0, 800, 600);

    //create element
    int heightPaddle(150), widthPaddle(15);
    leftPaddle = new Paddle(0, 0, widthPaddle, heightPaddle, true);
    rightPaddle = new Paddle(this->width() - widthPaddle, 0, widthPaddle, heightPaddle, false);
    ball = new Ball(this, 40);

    //add element to scene
    scene->addItem(leftPaddle);
    scene->addItem(rightPaddle);
    scene->addItem(ball);

    //add scene to view and show view
    this->setScene(scene);

}


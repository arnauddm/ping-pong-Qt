#include "game.hpp"
#include "limit.hpp"

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
    leftPaddle = new Paddle(0, 0, widthPaddle, heightPaddle, true, this->size());
    rightPaddle = new Paddle(this->width() - widthPaddle, 0, widthPaddle, heightPaddle, false, this->size());
    ball = new Ball(this, 40);
    top = new Limit(0, 0, this->size().width(), 0);
    bottom = new Limit(0, this->size().height(), this->size().width(), this->size().height());

    //add element to scene
    scene->addItem(leftPaddle);
    scene->addItem(rightPaddle);
    scene->addItem(ball);
    scene->addItem(top);
    scene->addItem(bottom);

    //add scene to view and show view
    this->setScene(scene);

}


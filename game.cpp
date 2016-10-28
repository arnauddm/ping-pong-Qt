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
    leftPaddle = new Paddle(0, 0, 15, 150);
    ball = new Ball(this, 40);

    //setting scene about leftElement
    scene->setFocusItem(leftPaddle);


    //add element to scene
    scene->addItem(leftPaddle);
    scene->addItem(ball);

    //add scene to view and show view
    this->setScene(scene);
    this->show();
}


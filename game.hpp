#ifndef GAME_HPP
#define GAME_HPP

#include "ball.hpp"
#include "paddle.hpp"
#include "limit.hpp"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTcpSocket>
#include <QTimer>
#include <iostream>

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game();

    void connect();

private:
    Ball *ball;
    Paddle *leftPaddle;
    Paddle *rightPaddle;
    Limit *top;
    Limit *bottom;
    QGraphicsScene *scene;

    //network element
    QTcpSocket *socket;
    uint sizeMessage;

    QTimer *timer;

    uint player;

    bool play;


signals:

public slots:
    void receiveData();
    void sendData();
    void disconnect();
    void errorSocket(QAbstractSocket::SocketError);
};

#endif // GAME_HPP

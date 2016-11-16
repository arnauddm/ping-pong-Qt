#ifndef GAME_HPP
#define GAME_HPP

#include "ball.hpp"
#include "paddle.hpp"
#include "limit.hpp"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTcpSocket>
#include <QTimer>

class Game : public QGraphicsView
{
public:
    Game();

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


signals:

public slots:
    void receiveData();
    void sendData();
    void connect();
    void disconnect();
    void errorSocket(QAbstractSocket::SocketError);
};

#endif // GAME_HPP

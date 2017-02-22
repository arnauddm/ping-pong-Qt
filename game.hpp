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
    void playing();

private:
    Ball *ball;
    Paddle *leftPaddle;
    Paddle *rightPaddle;
    Limit *top;
    Limit *bottom;
    QGraphicsScene *scene;

    //network element
    QTcpSocket *socket;
    quint16 sizeMessage;

    QTimer *timer;

    bool player1;


signals:

public slots:
    void receiveData();
    void sendData(QString &message);
    void disconnect();
    void errorSocket(QAbstractSocket::SocketError);
    void sendPosition();
};

#endif // GAME_HPP

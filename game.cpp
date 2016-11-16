#include "game.hpp"
#include "limit.hpp"

#define WIDTH 1000
#define HEIGHT 640

Game::Game()
{
    //create scene & view
    scene = new QGraphicsScene();

    //setting scene & view
    scene->setBackgroundBrush(Qt::white);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setFixedSize(WIDTH, HEIGHT);
    scene->setSceneRect(0, 0, WIDTH, HEIGHT);

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

    //create timer
    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(sendData()));

    //create netork element : socket
    socket = new QTcpSocket();

    //connect socket to slots
    QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(receiveData()));
    QObject::connect(socket, SIGNAL(connected()), this, SLOT(connect()));
    QObject::connect(socket, SIGNAL(disconnected()), this, SLOT(disconnect()));
    QObject::connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(errorSocket(QAbstractSocket::SocketError)));

    sizeMessage = 0;

}

void Game::sendData() {
    QString data;
    if(player == 1)
        data = QString::number(leftPaddle->getPos());
    else if(player == 2)
        data = QString::number(rightPaddle->getPos());

    //socket->write(data);
}

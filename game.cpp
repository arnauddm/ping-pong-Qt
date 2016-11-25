#include "game.hpp"
#include "limit.hpp"

#include <QMessageBox>

#define WIDTH 1000
#define HEIGHT 640

Game::Game()
{
    //create timer
    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(sendData()));

    //create netork element : socket
    socket = new QTcpSocket();

    //connect socket to slots
    QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(receiveData()));
    QObject::connect(socket, SIGNAL(disconnected()), this, SLOT(disconnect()));
    QObject::connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(errorSocket(QAbstractSocket::SocketError)));

    sizeMessage = 0;

    this->connect();
}

void Game::connect() {
    socket->abort();
    socket->connectToHost("127.0.0.1", 12345);
    std::cout << "Successful to connect to host !" << std::endl;
}

void Game::disconnect() {
    std::cout << "Disconnected" << std::endl;
}

void Game::receiveData() {
    QDataStream in(socket);

    if (sizeMessage == 0)
    {
        if (socket->bytesAvailable() < (int)sizeof(quint16))
            return;

        in >> sizeMessage;
    }

    if (socket->bytesAvailable() < sizeMessage)
        return;


    //if we are at this line of code, we have received the full message
    QString messageReceived;
    in >> messageReceived;

    //we reset this var for the next message
    sizeMessage = 0;

    QMessageBox::information(this, "DEBUG", messageReceived);

    if(messageReceived == "start")  this->playing();
    if(messageReceived == "first")  this->player1 = true;
    if(messageReceived == "second") this->player1 = false;

    QMessageBox::information(this, "Test", messageReceived);
}

void Game::errorSocket(QAbstractSocket::SocketError error) {
    //we print message in function of type of error
    std::cout << "!!! ERROR !!! ";
    switch (error) {

    case QAbstractSocket::HostNotFoundError:
        std::cout << "Server not found !" << std::endl;
        break;

    case QAbstractSocket::ConnectionRefusedError:
        std::cout << "Server refused your connection !" << std::endl;
        break;

    case QAbstractSocket::RemoteHostClosedError:
        std::cout << "Server closed connection !" << std::endl;
        break;

    default:
        std::cout << socket->errorString().toStdString();
        break;
    }
}

void Game::sendData() {
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    //we write size of message
    out << (quint16) 0;

    //we write message in byte array
    if(this->player1 == true)
        out << this->leftPaddle->getPos();
    else
        out << this->rightPaddle->getPos();

    //we select the position 0 of message
    out.device()->seek(0);
    //we write the real size of message in the beginning
    out << (quint16) (paquet.size() - sizeof(quint16));

    //we send data
    socket->write(paquet);
}

void Game::playing() {
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
    leftPaddle = new Paddle(0, 0, widthPaddle, heightPaddle, player1, this->size());
    rightPaddle = new Paddle(this->width() - widthPaddle, 0, widthPaddle, heightPaddle, !player1, this->size());
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

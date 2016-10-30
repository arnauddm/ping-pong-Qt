/*
 * Developped by Arnaud DE MATTEIS
 * All Right Reserved
 */

#include "game.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Game *game = new Game();
    game->show();
    return a.exec();
}

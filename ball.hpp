#ifndef BALL_HPP
#define BALL_HPP

#include <QGraphicsEllipseItem>
#include <QBrush>

class Ball : public QGraphicsEllipseItem
{
public:
    Ball(const unsigned int _x, const unsigned _y, const unsigned int _w, const unsigned int _h);

    void setX(const unsigned int pos);
    void setY(const unsigned int pos);
    void setPosition(const unsigned int posX, const unsigned int posY);
    void setPosition(QPoint pos);

    unsigned int getX(void);
    unsigned int getY(void);
    unsigned int getWidth(void);
    unsigned int getHeight(void);

private:
    unsigned int width;
    unsigned int height;
};

#endif // BALL_HPP

#include "position.h"

Position::Position()
{
    x = 0;
    y = 0;
}

Position::Position(int _x, int _y)
{
    x = _x;
    y = _y;
}

int Position::getX() const
{
    return x;
}

int Position::getY() const
{
    return y;
}

void Position::setX(const int _x)
{
    x = _x;
}

void Position::setY(const int _y)
{
    y = _y;
}

bool Position::operator==(const Position& b)
{
    return x == b.getX() && y == b.getY();
}

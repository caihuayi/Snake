#include "circle.h"
using namespace std;

Circle::Circle(int _d, int _ox, int _oy)
{
    pos.setX(0);
    pos.setY(0);
    diameter = _d;
    offset_x = _ox;
    offset_y = _oy;
    states = _right;
}

Circle::Circle(int _x, int _y, int _d, int _ox, int _oy)
{
    diameter = _d;
    offset_x = _ox;
    offset_y = _oy;
    states = _right;
    set_pos(_x, _y);
}

Circle::Circle(Position _p, int _d, int _ox, int _oy)
{
    diameter = _d;
    offset_x = _ox;
    offset_y = _oy;
    states = _right;
    pos = _p;
}

void Circle::set_pos(const Position _p)
{
    pos = _p;
}

void Circle::set_pos(const int _x, const int _y)
{
    pos.setX(_x);
    pos.setY(_y);
}

Position Circle::get_pos() const
{
    return pos;
}

void Circle::draw(QPainter *painter)
{
    cout << "draw in circle" << endl;
    cout << get_pixX() << " " << get_pixY() << endl;
    painter->drawEllipse(get_pixX(), get_pixY(), diameter, diameter);
}

Position& Circle::move()
{
    Direct d = instruction_queue.first();
    instruction_queue.pop_front();
    switch(d)
    {
    case _right:
        pos.setX(pos.getX()+1);
        break;
    case _left:
        pos.setX(pos.getX()-1);
        break;
    case _up:
        pos.setY(pos.getY()-1);
        break;
    case _down:
        pos.setY(pos.getY()+1);
        break;
    default:
        throw "wrong Derect";
    }

    return pos;
}

void Circle::instruct(Direct _di)
{
    states = _di;
    instruction_queue.push_back(_di);
}

inline int Circle::get_pixX()
{
    cout << pos.getX() << " " << diameter << " " << offset_x << endl;
    return pos.getX()*diameter-diameter/2+offset_x;
}

inline int Circle::get_pixY()
{
    cout << pos.getY() << " " << diameter << " " << offset_y << endl;
    return pos.getY()*diameter-diameter/2+offset_y;
}

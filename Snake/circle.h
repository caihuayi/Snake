#ifndef CIRCLE_H
#define CIRCLE_H
#include "position.h"
#include <QPainter>
#include <QQueue>
#include <iostream>
class Circle
{
public:
    typedef enum {_right, _up, _down, _left} Direct;
    Circle(int _d, int _ox, int _oy);
    Circle(int _x, int _y, int _d, int _ox, int _oy);
    Circle(Position _p, int _d, int _ox, int _oy);
    void set_pos(Position _p);
    void set_pos(const int _x, const int _y);
    Position get_pos() const;
    void draw(QPainter* painter);
    Position& move();
    void instruct(Direct _di);
    Direct get_states();
    void copy_queue(Circle &b);
protected:
    Position pos;
    int diameter;
    int offset_x;
    int offset_y;
    Direct states;
    QQueue<Direct> instruction_queue;

    int get_pixX();
    int get_pixY();
};

#endif // CIRCLE_H

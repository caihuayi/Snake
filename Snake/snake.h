#ifndef SNAKE_H
#define SNAKE_H
#include "position.h"
#include "circle.h"
#include <QList>
#include <QPainter>
#include <iostream>

class Snake
{
public:
    Snake(Position _p, int _l, int _d, int _ox, int _oy);
    ~Snake();
    Position get_first_position();
    void draw(QPainter* painter);
    void eat_apple();
    void instruct(Circle::Direct _now, Circle::Direct _d);
    void refresh();
private:
    void create_list();
    Circle* add_rear();
    QList<Circle*> circle_list;
    int length;
    Position first_pos;
    int offset_x;
    int offset_y;
    int circle_diameter;
    Circle::Direct states;
};

#endif // SNAKE_H

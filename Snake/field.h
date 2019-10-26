#ifndef FIELD_H
#define FIELD_H
#include "snake.h"
#include "rectangle.h"
#include "apple.h"
#include "circle.h"
#include "position.h"
#include <QPainter>
#include <iostream>
class Field
{
public:
    Field(int _x, int _y, int _d, int _w, int _h, int _l = 3);
    ~Field();
    bool up();
    bool down();
    bool left();
    bool right();
    void draw(QPainter*);
    void refresh();
    void create_apple();
    void eat_apple();
private:
    int offset_x;
    int offset_y;
    int diameter;
    int width;
    int height;
    Snake *snake;
    Circle::Direct states;
    Rectangle* rect;
    Apple *apple;

    bool is_in();
};

#endif // FIELD_H

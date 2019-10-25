#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <QPainter>
#include <iostream>

class Rectangle
{
public:
    Rectangle(int _x, int _y, int _d, int _w, int _h);
    void draw(QPainter *painter);
private:
    int offset_x;
    int offset_y;
    int width;
    int height;
    int diameter;

};

#endif // RECTANGLE_H

#include "rectangle.h"
using namespace std;

Rectangle::Rectangle(int _x, int _y, int _d, int _w, int _h)
{
    offset_x = _x;
    offset_y = _y;
    diameter = _d;
    width = _w;
    height = _h;
}

void Rectangle::draw(QPainter *painter)
{
    cout << "draw in rectangle" << endl;
    painter->drawRect(offset_x, offset_y, width*diameter, height*diameter);
}

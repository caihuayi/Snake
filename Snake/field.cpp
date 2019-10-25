#include "field.h"

Field::Field(int _x, int _y, int _d, int _w, int _h, int _l)
{
    Position pos(5, 5);
    offset_x = _x;
    offset_y = _y;
    diameter = _d;
    width = _w;
    height = _h;
    snake = new Snake(pos, _l, _d, offset_x, offset_y);
    rect = new Rectangle(_x, _y, _d, _w, _h);
}

Field::~Field()
{
    delete snake;
    delete rect;
}

bool Field::up()
{
    snake->instruct(Circle::_up);
    return is_in();
}

bool Field::down()
{
    snake->instruct(Circle::_down);
    return is_in();
}

bool Field::left()
{
    snake->instruct(Circle::_left);
    return is_in();
}

bool Field::right()
{
    snake->instruct(Circle::_right);
    return is_in();
}

void Field::draw(QPainter* painter)
{
    apple->draw(painter);
    snake->draw(painter);
    rect->draw(painter);
}

bool Field::is_in()
{
    Position pos = snake->get_first_position();
    if (pos.getX() < 0 || pos.getY() < 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

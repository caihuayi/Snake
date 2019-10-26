#include "field.h"
using namespace std;
Field::Field(int _x, int _y, int _d, int _w, int _h, int _l)
{
    Position pos(5, 5);
    offset_x = _x;
    offset_y = _y;
    diameter = _d;
    width = _w;
    height = _h;
    states = Circle::_right;
    snake = new Snake(pos, _l, _d, offset_x, offset_y);
    rect = new Rectangle(_x, _y, _d, _w, _h);
    apple = new Apple(width, height, diameter, offset_x, offset_y);
}

Field::~Field()
{
    delete snake;
    delete rect;
    if (apple != nullptr)
    {
        delete apple;
    }
}

bool Field::up()
{
    snake->instruct(states, Circle::_up);
    states = Circle::_up;
    return is_in();
}

bool Field::down()
{
    eat_apple();
    snake->instruct(states, Circle::_down);
    states = Circle::_down;
    return is_in();
}

bool Field::left()
{
    eat_apple();
    snake->instruct(states, Circle::_left);
    states = Circle::_left;
    return is_in();
}

bool Field::right()
{
    eat_apple();
    snake->instruct(states, Circle::_right);
    states = Circle::_right;
    return is_in();
}

void Field::draw(QPainter* painter)
{
    apple->draw(painter);
    snake->draw(painter);
    rect->draw(painter);
}

void Field::refresh()
{
    snake->refresh();
}

void Field::create_apple()
{
    apple = new Apple(width, height, diameter, offset_x, offset_y);
}

void Field::eat_apple()
{
    //cout << "is eat_apple?" << endl;
    //cout << snake->get_first_position().getX() << " " << snake->get_first_position().getY() << endl;
    //cout << apple->get_pos().getX() << " " << apple->get_pos().getY() << endl;
    if (snake->get_first_position() == apple->get_pos())
    {
        //cout << "eat apple" << endl;
        snake->eat_apple();
        delete apple;
        apple = new Apple(width, height, diameter, offset_x, offset_y);
    }
    else
    {
        //cout << "do not eat apple" << endl;
    }
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

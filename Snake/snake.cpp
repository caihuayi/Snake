#include "snake.h"
using namespace std;

Snake::Snake(Position _p, int _l, int _d, int _ox, int _oy)
{
    first_pos = _p;
    length = _l;
    offset_x = _ox;
    offset_y = _oy;
    circle_diameter = _d;
    create_list();
    states = Circle::_right;
}

Snake::~Snake()
{
    if (circle_list.empty()) return;
    for (auto &iter : circle_list)
    {
        delete iter;
    }
}

Position Snake::get_first_position()
{
    return first_pos;
}

void Snake::draw(QPainter* painter)
{
    if (circle_list.empty()) return;
    for (auto &iter : circle_list)
    {
        iter->draw(painter);
    }
    cout << "draw in snake" << endl;
}

void Snake::eat_apple()
{
    ++length;
    Circle *n = circle_list.first();
    switch(states)
    {
    case Circle::_up:
        circle_list.push_front(new Circle(n->get_pos().getX(), n->get_pos().getY()-1, circle_diameter, offset_x, offset_y));
        break;
    case Circle::_down:
        circle_list.push_front(new Circle(n->get_pos().getX(), n->get_pos().getY()+1, circle_diameter, offset_x, offset_y));
        break;
    case Circle::_right:
        circle_list.push_front(new Circle(n->get_pos().getX()+1, n->get_pos().getY(), circle_diameter, offset_x, offset_y));
        break;
    case Circle::_left:
        circle_list.push_front(new Circle(n->get_pos().getX()-1, n->get_pos().getY(), circle_diameter, offset_x, offset_y));
        break;
    default:
        throw "Direct is wrong";
    }
}

void Snake::instruct(Circle::Direct _d)
{
    if (circle_list.empty()) return;
    for (auto &iter : circle_list)
    {
        iter->instruct(_d);
    }
    states = _d;
}

void Snake::refresh()
{
    if (circle_list.empty()) return;
    for (auto &iter : circle_list)
    {
        iter->move();
    }
}

void Snake::create_list()
{
    if (first_pos.getX()-length < 0)
    {
        cout << "<0" << endl;
        throw "first_pos must bigger than length";
    }
    int y1 = first_pos.getY();
    int x1 = first_pos.getX();
    cout << length << endl;
    for (int i = 0; i < length; i++)
    {
        circle_list.append(new Circle(x1--, y1, circle_diameter, offset_x, offset_y));
    }
}

void Snake::add_head(Circle::Direct _d)
{

}

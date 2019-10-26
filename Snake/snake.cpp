#include "snake.h"
using namespace std;

Snake::Snake(Position _p, int _l, int _d, int _ox, int _oy)
{
    first_pos = _p;
    length = _l;
    offset_x = _ox;
    offset_y = _oy;
    circle_diameter = _d;
    states = Circle::_right;
    create_list();
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
    //cout << "draw in snake" << endl;
}

void Snake::eat_apple()
{
    ++length;
    //cout << "before add rear" << endl;
    circle_list.append(add_rear());
    //cout << "before add rear" << endl;
}

void Snake::instruct(Circle::Direct _now, Circle::Direct _next)
{
    if (circle_list.empty()) return;
    for (auto &iter : circle_list)
    {
        //cout << "Snake instruct for" << endl;
        iter->instruct(_next);
    }
    states = _next;
}

void Snake::refresh()
{
    //cout << "before refresh" << endl;
    if (circle_list.empty()) return;
    for (auto &iter : circle_list)
    {
        //cout << "in snake refresh for" << endl;
        iter->move();
    }
    first_pos = circle_list.first()->get_pos();
    //cout << "after refresh" << endl;
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
    int n = 0;
    for (auto &iter : circle_list)
    {
        //cout << "circle create for" << " " << states << " " << n << endl;;
        for (int i = 0; i < n; i++)
        {
            iter->instruct(states);
        }
        n++;
    }
}

Circle* Snake::add_rear()
{
    Circle *c = circle_list.back();
    Circle *d;
    Circle::Direct di = c->get_states();
    cout << "rear state: " << c->get_states() << endl;
    switch (di)
    {
    case Circle::_up:
        d = new Circle(c->get_pos().getX(), c->get_pos().getY()-1, circle_diameter, offset_x, offset_y);
        break;
    case Circle::_down:
        d = new Circle(c->get_pos().getX(), c->get_pos().getY()+1, circle_diameter, offset_x, offset_y);
        break;
    case Circle::_left:
        d = new Circle(c->get_pos().getX()+1, c->get_pos().getY(), circle_diameter, offset_x, offset_y);
        break;
    case Circle::_right:
        d = new Circle(c->get_pos().getX()-1, c->get_pos().getY()-1, circle_diameter, offset_x, offset_y);
        break;
    }
    cout << "copy_queue" << endl;
    d->copy_queue(*c);
    cout << "instruct" << endl;
    d->instruct(di);

    return d;
}



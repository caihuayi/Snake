#include "apple.h"
#include "circle.h"

Apple::Apple(int _width, int _height, int _d, int _ox, int _oy) : Circle(_d, _ox, _oy)
{
    QTime time;
    width = _width;
    height = _height;
    time = QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    pos.setX(qrand() % width);
    time = QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    pos.setY(qrand() % height);
}

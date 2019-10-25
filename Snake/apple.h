#ifndef APPLE_H
#define APPLE_H
#include "circle.h"
#include <QTime>

class Apple : public Circle
{
public:
    Apple(int _width, int _height, int _d, int _ox, int _oy);
private:
    int width;
    int height;
};

#endif // APPLE_H

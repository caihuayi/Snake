#ifndef POSITION_H
#define POSITION_H


class Position
{
public:
    Position();
    Position(int _x, int _y);
    int getX() const;
    int getY() const;
    void setX(const int _x);
    void setY(const int _y);
private:
    int x;
    int y;
};

#endif // POSITION_H

#include <bits/stdc++.h>
using namespace std;
class Point
{
private:
    float x, y;

public:
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(float _x, float _y)
    {
        x = _x;
        y = _y;
    }
    void printPoint()
    {
        cout << "(" << x << ", " << y << ")";
    }
    float getX()
    {
        return x;
    }
    float getY()
    {
        return y;
    }
    void setX(float _x)
    {
        x = _x;
    }
    void setY(float _y)
    {
        y = _y;
    }
    float getDistance(Point &p)
    {
        return sqrt((x - p.x)*(x - p.x) + (y - p.y)*(y - p.y));
    }
};
class Segment
{
private:
    Point point1, point2;

public:
    Segment()
    {
        point1.setX(0);
        point1.setY(0);
        point2.setX(0);
        point2.setY(0);
    }
    Segment(Point _point1, Point _point2)
    {
        point1 = _point1;
        point2 = _point2;
    }
    float getLength()
    {
        return sqrt((point1.getX() - point2.getX())*(point1.getX() - point2.getX()) + (point1.getY() - point2.getY())*(point1.getY() - point2.getY()));
    }
};

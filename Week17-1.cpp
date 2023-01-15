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
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
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
    Point getpoint1()
    {
        return point1;
    }
    Point getpoint2()
    {
        return point2;
    }
    float getLength()
    {
        return sqrt((point1.getX() - point2.getX()) * (point1.getX() - point2.getX()) + (point1.getY() - point2.getY()) * (point1.getY() - point2.getY()));
    }
};

class Shape
{
public:
    Shape()
    {
        edgeCount = 0;
    }
    Shape(Segment *l, int x)
    {
        for (int i = 0; i < x; i++)
        {
            bool flag = 1;
            for (int j = 0; j < x; j++)
            {
                if (i == j)
                    continue;
                if (l[i].getpoint2().getX() == l[j].getpoint1().getX() and l[i].getpoint2().getY() == l[j].getpoint1().getY())
                    flag = 0;
            }
            if (flag)
            {
                throw invalid_argument("occur error!");
                break;
            }
        }
        for (int i = 0; i < x; i++)
        {
            seg[i] = l[i];
        }
        edgeCount = x;
    }
    virtual float getArea() = 0;
    float getPerimeter()
    {
        float sum = 0;
        for (int i = 0; i < edgeCount; i++)
        {
            sum += seg[i].getLength();
        }
        return sum;
    }
    Segment &getSeg(int index)
    {
        return seg[index];
    }

private:
    Segment seg[10];
    int edgeCount;
};
class Circle : public Shape
{
private:
    float radius;
public:
  Circle (float r):radius(r){};
  float getArea(){return radius*radius*3.141592;};
  float getPerimeter(){return 2*radius*3.141592;};
};

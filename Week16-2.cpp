#include <bits/stdc++.h>
using namespace std;
template <typename T>
class point
{
  private:
  T x = 0, y = 0;
  public:
  point() = default;
  point(T a, T b):x(a),y(b){}
  point operator+(const point &win)
  {
   	return point(this->x+win.x,this->y+win.y);
  }
    friend ostream& operator<<(ostream& os, const point &p)
    {
        os << setprecision(2) << fixed << p.x << " " << p.y << endl;
        return os;
    }
};

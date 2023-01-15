#include<bits/stdc++.h>
using namespace std;
class Convert
{
public:
  static string toString(int n)
  {
    stringstream aa;
    aa<<n;
    return aa.str();
  }
  static string toString(char c)
  {
    stringstream bb;
    bb<<c;
    return bb.str();
  }
  static string toString(double d)
  {
    stringstream cc;
    cc<<d;
    return cc.str();
  }
  static string toString(Point p)
  {
    stringstream dd,ee;
    dd<<p.x;
    ee<<p.y;
    return "(" + dd.str()+", "+ee.str()+")";
  }
};

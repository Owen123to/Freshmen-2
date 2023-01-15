#include <bits/stdc++.h>
using namespace std;
class Convert:public string
{
public:
    int toInt(){return stoi(*this);}
    double toDouble(){return stod(*this);}
};

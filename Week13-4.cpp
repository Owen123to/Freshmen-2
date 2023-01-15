#include <bits/stdc++.h>
using namespace std;
class Date
{
public:
  Date()
  {
    year = 1;
    month = 1;
    day = 1;
  }
  Date(int y, int m, int d)
  {
    year = y;
    month = m;
    day = d;
  }
  virtual string toString()
  {
    stringstream  temp1,temp2,temp3;
  	temp1<<month;
  	temp2<<day;
    temp3<<year;
    return temp1.str()+", "+temp2.str()+", "+temp3.str();
  } // "mm, dd, yyyy"
  void setDay(int d) {day = d;}
  void setMonth(int m) {month = m;}
  void setYear(int y){year = y;}
  int getDay() const{return day;}
  int getMonth() const {return month;}
  int getYear() const {return year;}
  void addDays(int d){day+=d;} // adds the specified number of days to this instance
  void addMonths(int m){month+=m;}// adds the specified number of months to this instance
  void addYears(int y){year+=y;}// adds the specified number of years to this instance
  static bool isLeapYear(const Date &d)
  {
    if(d.year%4==0)
    {
		if(d.year%100==0)
        {
          if(d.year%400 == 0)
            return true;
          else
            return false;
        }
      else
        return true;
    }
    else
      return false;
  }
private:
  int year, month, day;
};
class TimeSpan
{
public:
  TimeSpan();
  TimeSpan(int d, int hh, int mm, int ss)
  {
    	day = d;
        hour = hh;
        minute = mm;
        second = ss;
  }
  int toTotalDays(){return toTotalHours()/24;}
  int toTotalHours(){return toTotalMinutes()/60;}
  int toTotalMinutes(){return toTotalSeconds()/60;}
  int toTotalSeconds(){return ((day*24+hour)*60+minute)*60+second;}
  string toString()
  {
    stringstream temp1,temp2,temp3,temp4;
    temp1<<day;
    temp2<<hour;
    temp3<<minute;
    temp4<<second;
    return temp1.str() + " " + temp2.str() + ":" + temp3.str() + ":" + temp4.str();
  }
private:
  int day, hour, minute, second;
};
class DateTime : public Date
{
public:
  virtual string toString()
  {
  	stringstream temp1,temp2,temp3;
    temp1<<hour;
    temp2<<minute;
    temp3<<second;
    return Date::toString()+" " + temp1.str() + ":" + temp2.str() + ":" + temp3.str();
  } // "mm/dd/yyyy HH:MM:SS"
  DateTime() : Date()
  {
    hour = 0;
    minute = 0;
    second = 0;
  }
  DateTime(int y, int m, int d, int hh, int mm, int ss) : Date(y, m, d)
  {
    hour = hh;
    minute = mm;
    second = ss;
  }
  void setHour(int h){hour = h;}
  void setMinute(int m){minute = m;}
  void setSecond(int s){second = s;}
  int getHour() const{return hour;}
  int getMinute() const{return minute;}
  int getSecond() const{return second;}
  void addHours(int h){hour+=h;}// adds the specified number of hours to this instance
  void addMinutes(int m){minute+=m;}// adds the specified number of minutes to this instance
  void addSeconds(int s){second+=s;}// adds the specified number of seconds to this instance
  TimeSpan operator-(const DateTime &dt) const
  {
        int sum1=0,sum2=0;
        for (int i=1;i<getYear();i++)
        {
            if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
            {
                sum1+=366;
            }
            else
            {
                sum1+=365;
            }
        }
        for (int i=1;i<dt.getYear();i++)
        {
            if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
            {
                sum2+=366;
            }
            else
            {
                sum2+=365;
            }
        }
        for (int i=1;i<getMonth();i++)
        {
            if (i==1) sum1+=31;
            else if (i == 2 && ((getYear() % 4 == 0 && getYear() % 100 != 0) || (getYear() % 400 == 0)))
                sum1+=29;
            else if (i == 2 && !((getYear() % 4 == 0 && getYear() % 100 != 0) || (getYear() % 400 == 0)))
                sum1+=28;
            else if (i==3) sum1+=31;
            else if (i==4) sum1+=30;
            else if (i==5) sum1+=31;
            else if (i==6) sum1+=30;
            else if (i==7) sum1+=31;
            else if (i==8) sum1+=31;
            else if (i==9) sum1+=30;
            else if (i==10) sum1+=31;
            else if (i==11) sum1+=30;
            else if (i==12) sum1+=31;
        }
        for (int i=1;i<dt.getMonth();i++)
        {
            if (i==1) sum2+=31;
            else if (i == 2 && ((getYear() % 4 == 0 && getYear() % 100 != 0) || (getYear() % 400 == 0)))
                sum2+=29;
            else if (i == 2 && !((getYear() % 4 == 0 && getYear() % 100 != 0) || (getYear() % 400 == 0)))
                sum2+=28;
            else if (i==3) sum2+=31;
            else if (i==4) sum2+=30;
            else if (i==5) sum2+=31;
            else if (i==6) sum2+=30;
            else if (i==7) sum2+=31;
            else if (i==8) sum2+=31;
            else if (i==9) sum2+=30;
            else if (i==10) sum2+=31;
            else if (i==11) sum2+=30;
            else if (i==12) sum2+=31;
        }
        int daygap, hourgap, minutegap, secondgap;
        int carry = 0;
        daygap = (getDay()+sum1 - dt.getDay()-sum2);
        if (daygap > 0)
        {
            secondgap = (getSecond() - dt.getSecond());
            if (secondgap < 0)
            {
                secondgap += 60;
                carry = 1;
            }
            minutegap = (getMinute() - dt.getMinute()) - carry;
            if (minutegap < 0)
            {
                minutegap += 60;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            hourgap = (getHour() - dt.getHour()) - carry;
            if (hourgap < 0)
            {
                hourgap += 24;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            if (carry)
            {
                daygap -= 1;
            }
        }
        else
        {
            daygap = (dt.getDay()+sum2 - getDay()-sum1 );
            secondgap = (dt.getSecond() - getSecond());
            if (secondgap < 0)
            {
                secondgap += 60;
                carry = 1;
            }
            minutegap = (dt.getMinute() - getMinute()) - carry;
            if (minutegap < 0)
            {
                minutegap += 60;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            hourgap = (dt.getHour() - getHour()) - carry;
            if (hourgap < 0)
            {
                hourgap += 24;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            if (carry)
            {
                daygap -= 1;
            }
        }
        TimeSpan *ts = new TimeSpan(daygap, hourgap, minutegap, secondgap);
        return *ts;
    }
private:
  int hour, minute, second;
};
int main() {
  int y, m, d, hh, mm, ss;
  cin>>y>>m>>d>>hh>>mm>>ss;
  DateTime d1(y, m, d, hh, mm, ss);
  cin>>y>>m>>d>>hh>>mm>>ss;
  DateTime d2(y, m, d, hh, mm, ss);
  cout<<(d1 - d2).toTotalSeconds();
  return 0;
}

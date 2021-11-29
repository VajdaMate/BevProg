#include "../../std_lib_facilities.h"


struct Date 
{
	int y, m, d;
	Date(int y, int m, int d);
	void add_day(int n);

};
Date::Date(int year, int month, int day)
{
	if (year > 0)
		y = year;
	else
		error("Invalid year");
	if (month < 13 && month > 0)
		m = month;
	else
		error("Invalid month");
	if (day > 0 && day < 32)
		d = day;
	else
		error("Invalid day");
}

void Date::add_day(int n)
{
	d += n;
	if (d > 31) 
	{
		++m;
		d -= 31;
		if (m >12)
		{
			++y;
			m -= 12;
		}
	}
}

ostream& operator<<(ostream& os, const Date d)
{
	return os << d.y<<". "<<d.m<<". "<<d.d<<'\n';
}

int main()
{

Date today{1978,6,25};
cout<<"Date: "<<today;
today.add_day(1);
Date tomorrow = today;
cout<<"Date: "<<tomorrow;

return 0;	
}

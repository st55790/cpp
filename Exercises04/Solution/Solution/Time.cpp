#include "Time.h"


Time::Time()
{
	this->_Hours = 0;
	this->_Minutes = 0;
	this->_Seconds = 0;
}

Time::~Time()
{
}

Time::Time(int hours, int minutes, int seconds)
{
	this->_Hours = hours;
	this->_Minutes = minutes;
	this->_Seconds = seconds;
}

int Time::CompareTo(IComparable* obj) const
{
	Time* tmpTime = dynamic_cast<Time*>(obj);
	if (_Hours > tmpTime->_Hours) {
		return 1;
	}
	else if (_Hours == tmpTime->_Hours) {
		if (_Minutes == tmpTime->_Minutes) {
			if (_Seconds == tmpTime->_Seconds) {
				return 0;
			}
			else if (_Seconds > tmpTime->_Seconds) {
				return 1;
			}
			else {
				return -1;
			}
		}
		else if (_Minutes > tmpTime->_Minutes) {
			return 1;
		}
		else {
			return -1;
		}
	}
	else {
		return -1;
	}
}

string Time::ToString() const
{
	string h = to_string(_Hours);
	string m = to_string(_Minutes);
	string s = to_string(_Seconds);
	if (h.length() == 1) {
		h = '0' + h;
	}
	if (m.length() == 1) {
		m = '0' + m;
	}
	if (s.length() == 1) {
		s = '0' + s;
	}
	return "Time-> " + h + ":" + m + ":" + s;
}

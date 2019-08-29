/*
 * Date.cpp
 *
 *  Created on: Aug 29, 2019
 *      Author: tbmnxvmuser
 */


#include "Date.h"
#include <ctime>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <cctype>
#include <vector>

bool Date::String2Int (string s, int& number)
{
	std::istringstream stream(s);
	stream >> number;
	if (stream.fail())
	{
		stream.clear();
		return false;
	}

	return true;
}

int Date::String2Vector (string str, vector<int>& numbers)
{
	int number;
	size_t pos = 0;
	std::string token;

	while ((pos = str.find(delimiter)) != std::string::npos)
	{
	    token = str.substr(0, pos);

	    if (!String2Int(token, number))
	    	break;

		numbers.push_back(number);
		str.erase(0, pos + delimiter.length());
	}

    if (String2Int(str, number))
    {
    	numbers.push_back(number);
    }

    return numbers.size();
}

Date::Date (string date)
{
	vector<int> numbers;

	if (String2Vector(date, numbers) != 3)
	{
		throw std::exception();
	}
	else
	{
		   time_t rawtime;
		   tm* timeinfo;

		   time ( &rawtime );
		   timeinfo = localtime ( &rawtime );
		   timeinfo->tm_mday = numbers[0];
		   timeinfo->tm_mon = numbers[1] -1;
		   timeinfo->tm_year = numbers[2]-1900;
		   unixts = mktime(timeinfo);
	}
}

bool Date::operator==(const Date& date) const
{
	tm tmp_l_time, tmp_c_time;
	time_t l_unixts = date.GetUnixTimestamp();

	tm* l_time = localtime_r(&l_unixts, &tmp_l_time);
	tm* c_time = localtime_r(&this->unixts, &tmp_c_time);

	return ((c_time->tm_year == l_time->tm_year) &&
			(c_time->tm_mon == l_time->tm_mon) &&
			(c_time->tm_mday == l_time->tm_mday));
}

string Date::ToString()
{
	time_t tmp = unixts;
	tm* timeinfo = localtime ( &tmp );

	return std::to_string(timeinfo->tm_mday)+"/"+std::to_string(timeinfo->tm_mon+1)+"/"+std::to_string(timeinfo->tm_year+1900);
}

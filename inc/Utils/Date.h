/*
 * Date.h
 *
 *  Created on: Aug 29, 2019
 *      Author: tbmnxvmuser
 */

#ifndef DATE_H_
#define DATE_H_

#include <string>
#include <vector>

using namespace std;

// format dd/mm/yyyy

class Date {
private:
	const string delimiter = "/";
	time_t unixts;

	bool String2Int (string s, int& number);
	int String2Vector (string s, vector<int>& numbers);

public:
	Date (string date);
	time_t GetUnixTimestamp() const { return unixts; }
	tm* GetTimeinfo() const { return localtime(&unixts); }
	string ToString();

	bool operator==(const Date& date) const;
};




#endif /* DATE_H_ */

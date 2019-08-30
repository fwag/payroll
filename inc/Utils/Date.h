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
enum DayOfWeek {
	Sunday = 0,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday
};

class Date {
private:
	const string delimiter = "/";
	time_t unixts;

	bool String2Int (string s, int& number);
	int String2Vector (string s, vector<int>& numbers);

public:
	Date (string date);
	Date (time_t unixts);

	time_t GetUnixTimestamp() const { return unixts; }
	tm* GetTimeinfo() const { return localtime(&unixts); }

	DayOfWeek GetDayOfWeek();
	int GetDay() { return this->GetTimeinfo()->tm_mday; }
	int GetMonth() { return this->GetTimeinfo()->tm_mon+1; }
	int GetYear() { return this->GetTimeinfo()->tm_year+1900; }

	int Days2Seconds (int days);
	Date AddDays (int days);
	static int GetLastDayOfMonth (int month, int year);
	string ToString();

	bool operator==(const Date& date) const;

	bool operator> (const Date& date) const { return this->unixts>date.GetUnixTimestamp(); }
    bool operator>= (const Date& date) const { return this->unixts>=date.GetUnixTimestamp(); }
	bool operator< (const Date& date) const { return this->unixts<date.GetUnixTimestamp(); }
    bool operator<= (const Date& date) const { return this->unixts<=date.GetUnixTimestamp(); }
};




#endif /* DATE_H_ */

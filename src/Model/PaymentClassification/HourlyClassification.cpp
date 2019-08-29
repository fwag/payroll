/*
 * HourlyClassification.cpp
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#include "HourlyClassification.h"
#include <algorithm>

namespace Payroll {

float HourlyClassification::CalculateDailyRate (int hours)
{
	float pay = 0.0;
	if (hours > 8)
		pay = (hours-8)*1.5*hourlyRate;

	pay += 8*hourlyRate;

	return pay;
}

float HourlyClassification::CalculatePay (time_t date)
{
	tm *payDate = localtime(&date);
	vector<TimeCard>::iterator it;
	float pay = 0.0;
	tm *tcDate;

	for (it = timecards.begin(); it != timecards.end(); it++)
	{
		time_t tcDate_t = (*it).GetDate();
		tcDate = localtime(&tcDate_t);
		if (tcDate->tm_mday >= payDate->tm_mday)
		{
			pay += CalculateDailyRate((*it).GetHours());
		}
	}
	return pay;
}

void HourlyClassification::AddTimeCard (TimeCard card)
{
	timecards.push_back(card);
}

TimeCard HourlyClassification::GetTimeCard (time_t date)
{
	TimeCard ret {0, -1.0};

	vector<TimeCard>::iterator it;
	it = find_if(timecards.begin(), timecards.end(), [&date](TimeCard tc){
		time_t rawtime = tc.GetDate();
		tm* ltm1 = localtime(&rawtime);
		tm* ltm2 = localtime(&date);
		return ((ltm1->tm_year == ltm2->tm_year) &&
				(ltm1->tm_mon == ltm2->tm_mon) &&
				(ltm1->tm_mday == ltm2->tm_mday));
	});

	if (it != timecards.end()) ret = *it;
	return ret;
}

} /* namespace Payroll */

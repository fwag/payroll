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

float HourlyClassification::CalculatePay (Paycheck paycheck)
{
	//tm *payDate = date.GetTimeinfo();
	vector<TimeCard>::iterator it;
	float pay = 0.0;
	//tm *tcDate;

	for (it = timecards.begin(); it != timecards.end(); it++)
	{
		//tcDate = (*it).GetDate().GetTimeinfo();
		//if (tcDate->tm_mday >= payDate->tm_mday)
		if (paycheck.IsInPayPeriod((*it).GetDate()))
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

unique_ptr<TimeCard> HourlyClassification::GetTimeCard (Date date)
{
	vector<TimeCard>::iterator it;
	it = find_if(timecards.begin(), timecards.end(), [&date](TimeCard tc){
		return date == tc.GetDate();
	});

	if (it == timecards.end()) return unique_ptr<TimeCard>{nullptr};

	return unique_ptr<TimeCard>(new TimeCard{*it});
}

} /* namespace Payroll */

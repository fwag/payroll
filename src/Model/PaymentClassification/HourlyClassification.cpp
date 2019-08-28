/*
 * HourlyClassification.cpp
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#include "HourlyClassification.h"

namespace Payroll {

float HourlyClassification::CalculateDailyRate (int hours)
{
	float pay = 0.0;
	if (hours > 8)
		pay = (hours-8)*1.5*hourlyRate;

	pay += hours*hourlyRate;

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


} /* namespace Payroll */

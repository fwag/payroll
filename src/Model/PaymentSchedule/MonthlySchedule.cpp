/*
 * MonthlySchedule.cpp
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#include "MonthlySchedule.h"

namespace Payroll {


bool MonthlySchedule::IsPayday(Date date)
{
	bool res = false;
	int lastDayOfMonth;

	lastDayOfMonth = Date::GetLastDayOfMonth (date.GetMonth(), date.GetYear());

	if (date.GetDay() == lastDayOfMonth)
	{
		res = true;
	}

	return res;
}

Date MonthlySchedule::GetPayPeriodStartDate (Date date)
{
	int days = 0;
	while(date.AddDays(days - 1).GetMonth() == date.GetMonth())
		days--;

	return date.AddDays(days);
}

} /* namespace Payroll */

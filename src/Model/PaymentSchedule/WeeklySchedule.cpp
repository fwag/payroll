/*
 * WeeklySchedule.cpp
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#include "WeeklySchedule.h"

namespace Payroll {

bool WeeklySchedule::IsPayday(Date date)
{
	bool res = false;

	if (date.GetDayOfWeek() == DayOfWeek::Friday)
	{
		res = true;
	}

	return res;
}

Date WeeklySchedule::GetPayPeriodStartDate (Date date)
{
	return date.AddDays(-6);
}

} /* namespace Payroll */

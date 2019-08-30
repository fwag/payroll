/*
 * BiweeklySchedule.cpp
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#include "BiweeklySchedule.h"

namespace Payroll {

bool BiweeklySchedule::IsPayday(Date date)
{
	bool res = false;

	if ((date.GetDayOfWeek() == DayOfWeek::Friday) && (date.GetDay()%2 == 0))
	{
		res = true;
	}

	return res;
}

Date BiweeklySchedule::GetPayPeriodStartDate (Date date)
{
	return date.AddDays(-13);
}

} /* namespace Payroll */

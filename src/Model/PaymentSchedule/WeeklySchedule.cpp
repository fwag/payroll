/*
 * WeeklySchedule.cpp
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#include "WeeklySchedule.h"

namespace Payroll {

bool WeeklySchedule::IsPayday(time_t date)
{
	bool res = false;
	tm *ltm = localtime(&date);

	if (ltm->tm_wday == LAST_WEEK_DAY)
	{
		res = true;
	}

	return res;
}

} /* namespace Payroll */

/*
 * WeeklySchedule.cpp
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#include "BiweeklySchedule.h"

namespace Payroll {

bool BiweeklySchedule::IsPayday(time_t date)
{
	bool res = false;
	tm *ltm = localtime(&date);

	if (ltm->tm_wday == LAST_WEEK_DAY && ltm->tm_mday%2 == 0)
	{
		res = true;
	}

	return res;
}

} /* namespace Payroll */

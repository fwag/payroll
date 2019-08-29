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
	tm *ltm = date.GetTimeinfo();

	if (ltm->tm_wday == LAST_WEEK_DAY && ltm->tm_mday%2 == 0)
	{
		res = true;
	}

	return res;
}

} /* namespace Payroll */

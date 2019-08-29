/*
 * TimeCard.h
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#ifndef TIMECARD_H_
#define TIMECARD_H_

#include "Date.h"

namespace Payroll {

class TimeCard {
private:
	Date date;
	float hours;

public:
	TimeCard(Date date, float hours):
		date{date},
		hours{hours}
	{}

	float GetHours()
	{
		return hours;
	}

	Date GetDate()
	{
		return date;
	}
};

} /* namespace Payroll */

#endif /* TIMECARD_H_ */

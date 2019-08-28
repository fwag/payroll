/*
 * TimeCard.h
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#ifndef TIMECARD_H_
#define TIMECARD_H_

namespace Payroll {

class TimeCard {
private:
	time_t date;
	float hours;

public:
	TimeCard(time_t date, float hours):
		date{date},
		hours{hours}
	{}

	float GetHours()
	{
		return hours;
	}

	time_t GetDate()
	{
		return date;
	}
};

} /* namespace Payroll */

#endif /* TIMECARD_H_ */

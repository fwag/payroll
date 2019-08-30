/*
 * WeeklySchedule.h
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#ifndef WEEKLYSCHEDULE_H_
#define WEEKLYSCHEDULE_H_

#include "PaymentSchedule.h"
#include <ctime>
#include "Date.h"

namespace Payroll {

class WeeklySchedule : public PaymentSchedule {
public:
	bool IsPayday (Date date) final;
	Date GetPayPeriodStartDate (Date date);
};

} /* namespace Payroll */

#endif /* WEEKLYSCHEDULE_H_ */

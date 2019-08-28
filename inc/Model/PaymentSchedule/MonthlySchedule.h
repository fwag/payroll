/*
 * MonthlySchedule.h
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#ifndef MONTHLYSCHEDULE_H_
#define MONTHLYSCHEDULE_H_

#include "PaymentSchedule.h"
#include <ctime>

namespace Payroll {

class MonthlySchedule : public PaymentSchedule {
public:
	bool IsPayday (time_t date);
private:
	int GetLastMonthDay (int month, int year);

};

} /* namespace Payroll */

#endif /* MONTHLYSCHEDULE_H_ */

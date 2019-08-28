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

namespace Payroll {

class BiweeklySchedule : public PaymentSchedule {
public:
	bool IsPayday (time_t date) final;
};

} /* namespace Payroll */

#endif /* WEEKLYSCHEDULE_H_ */

/*
 * BiweeklySchedule.h
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#ifndef BIWEEKLYSCHEDULE_H_
#define BIWEEKLYSCHEDULE_H_

#include "PaymentSchedule.h"
#include <ctime>
#include "Date.h"

namespace Payroll {

class BiweeklySchedule : public PaymentSchedule {
public:
	bool IsPayday (Date date) final;
};

} /* namespace Payroll */

#endif /* BIWEEKLYSCHEDULE_H_ */

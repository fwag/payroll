/*
 * PaymentSchedule.h
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#ifndef PAYMENTSCHEDULE_H_
#define PAYMENTSCHEDULE_H_

#include <ctime>
#include "Date.h"

namespace Payroll {

class PaymentSchedule {
public:
	virtual bool IsPayday(Date date) = 0;
	virtual Date GetPayPeriodStartDate(Date date)= 0;

};

} /* namespace Payroll */

#endif /* PAYMENTSCHEDULE_H_ */

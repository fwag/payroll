/*
 * PaymentClassification.h
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#ifndef PAYMENTCLASSIFICATION_H_
#define PAYMENTCLASSIFICATION_H_

#include <ctime>
#include "Paycheck.h"

namespace Payroll {

class PaymentClassification {
public:
	PaymentClassification();
	virtual ~PaymentClassification();

	virtual float CalculatePay(Paycheck paycheck) = 0;

};

} /* namespace Payroll */

#endif /* PAYMENTCLASSIFICATION_H_ */

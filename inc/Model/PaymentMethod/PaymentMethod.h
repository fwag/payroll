/*
 * PaymentMethod.h
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#ifndef PAYMENTMETHOD_H_
#define PAYMENTMETHOD_H_

#include "Paycheck.h"
#include <memory>

namespace Payroll {

class PaymentMethod {
public:
	virtual void Pay(shared_ptr<Paycheck> paycheck) = 0;
};

} /* namespace Payroll */

#endif /* PAYMENTMETHOD_H_ */

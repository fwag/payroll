/*
 * PaymentMethod.h
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#ifndef PAYMENTMETHOD_H_
#define PAYMENTMETHOD_H_

namespace Payroll {

class PaymentMethod {
public:
	virtual void pay() = 0;
};

} /* namespace Payroll */

#endif /* PAYMENTMETHOD_H_ */

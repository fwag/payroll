/*
 * HoldMethod.h
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#ifndef HOLDMETHOD_H_
#define HOLDMETHOD_H_

#include "PaymentMethod.h"

namespace Payroll {

class HoldMethod : public PaymentMethod {
public:
	void pay() final { }
};

} /* namespace Payroll */

#endif /* HOLDMETHOD_H_ */

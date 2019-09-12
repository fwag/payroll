/*
 * HoldMethod.h
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#ifndef HOLDMETHOD_H_
#define HOLDMETHOD_H_

#include "PaymentMethod.h"
#include "Paycheck.h"

namespace Payroll {

class HoldMethod : public PaymentMethod {
public:
	void Pay(shared_ptr<Paycheck> paycheck) final {
		paycheck->SetField("Disposition", "Hold");
	}
};

} /* namespace Payroll */

#endif /* HOLDMETHOD_H_ */

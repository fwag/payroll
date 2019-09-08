/*
 * ChangeHoldTransaction.h
 *
 *  Created on: Sep 8, 2019
 *      Author: tbmnxvmuser
 */

#ifndef CHANGEHOLDTRANSACTION_H_
#define CHANGEHOLDTRANSACTION_H_

#include "HoldMethod.h"
#include "ChangeMethodTransaction.h"
#include <memory>

namespace Payroll
{

class ChangeHoldTransaction : public ChangeMethodTransaction
{
public:
	ChangeHoldTransaction(int empId) : ChangeMethodTransaction(empId) {}

	shared_ptr<PaymentMethod> GetMethod()
	{
		return make_shared<HoldMethod>();
	}
};

}


#endif /* CHANGEHOLDTRANSACTION_H_ */

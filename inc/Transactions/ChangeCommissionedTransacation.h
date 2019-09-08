/*
 * ChangeCommissionedTransacation.h
 *
 *  Created on: Sep 8, 2019
 *      Author: tbmnxvmuser
 */

#ifndef CHANGECOMMISSIONEDTRANSACATION_H_
#define CHANGECOMMISSIONEDTRANSACATION_H_


#include <memory>
#include "ChangeClassificationTransaction.h"

namespace Payroll
{
class ChangeCommissionedTransaction : public ChangeClassificationTransaction
{
private:
	float salary;
	float commissionRate;

public:
	ChangeCommissionedTransaction(int memId, float salary, float commissionRate) :
		ChangeClassificationTransaction(memId), salary{salary}, commissionRate{commissionRate}
	{}

	shared_ptr<PaymentClassification> GetClassification()
	{
		return make_shared<CommissionedClassification>(salary,commissionRate);
	}

	shared_ptr<PaymentSchedule> GetSchedule()
	{
		return make_shared<BiweeklySchedule>();
	}

};

}


#endif /* CHANGECOMMISSIONEDTRANSACATION_H_ */

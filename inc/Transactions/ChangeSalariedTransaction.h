/*
 * ChangeSalariedTransaction.h
 *
 *  Created on: Sep 8, 2019
 *      Author: tbmnxvmuser
 */

#ifndef CHANGESALARIEDTRANSACTION_H_
#define CHANGESALARIEDTRANSACTION_H_

#include <memory>
#include "ChangeClassificationTransaction.h"


namespace Payroll
{
class ChangeSalariedTransaction : public ChangeClassificationTransaction
{
private:
	float salary;

public:
	ChangeSalariedTransaction(int memId, float salary) :
		ChangeClassificationTransaction(memId), salary{salary}
	{}

	shared_ptr<PaymentClassification> GetClassification()
	{
		return make_shared<SalariedClassification>(salary);
	}

	shared_ptr<PaymentSchedule> GetSchedule()
	{
		return make_shared<MonthlySchedule>();
	}

};

}

#endif /* CHANGESALARIEDTRANSACTION_H_ */

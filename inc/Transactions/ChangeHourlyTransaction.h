/*
 * ChangeHourlyTransaction.h
 *
 *  Created on: Sep 8, 2019
 *      Author: tbmnxvmuser
 */

#ifndef CHANGEHOURLYTRANSACTION_H_
#define CHANGEHOURLYTRANSACTION_H_

#include <memory>
#include "ChangeClassificationTransaction.h"

namespace Payroll
{
class ChangeHourlyTransaction : public ChangeClassificationTransaction
{
private:
	float hourlyRate;

public:
	ChangeHourlyTransaction(int memId, float hourlyRate) :
		ChangeClassificationTransaction(memId), hourlyRate{hourlyRate}
	{}

	shared_ptr<PaymentClassification> GetClassification()
	{
		return make_shared<HourlyClassification>(hourlyRate);
	}

	shared_ptr<PaymentSchedule> GetSchedule()
	{
		return make_shared<WeeklySchedule>();
	}

};

}

#endif /* CHANGEHOURLYTRANSACTION_H_ */

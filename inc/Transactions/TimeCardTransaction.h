/*
 * TimeCardTransaction.h
 *
 *  Created on: Sep 1, 2019
 *      Author: tbmnxvmuser
 */

#ifndef TIMECARDTRANSACTION_H_
#define TIMECARDTRANSACTION_H_

#include "Transaction.h"
#include "Date.h"
#include "TimeCardTransaction.h"

namespace Payroll {
class TimeCardTransaction : public Transaction {
private:
	Date date;
	float hours;
	int empId;

public:
	TimeCardTransaction (Date date, float hours, int empId) :
		date {date}, hours{hours},  empId{empId}
		{

		}

	void Execute()
	{
		shared_ptr<Employee> e = PayrollDatabase::GetEmployee(empId);

		if (e != nullptr)
		{
			shared_ptr<HourlyClassification> hc = dynamic_pointer_cast<HourlyClassification>(e->classification);

			if (hc != nullptr)
			{
				hc->AddTimeCard(TimeCard{date,hours});
			} else {
				runtime_error("Tried to add timecard to non-hourly employee");
			}
		} else {
			runtime_error("No such employee");
		}
	}
};
}


#endif /* TIMECARDTRANSACTION_H_ */

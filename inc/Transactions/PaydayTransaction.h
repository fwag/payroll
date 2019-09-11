/*
 * PaydayTransaction.h
 *
 *  Created on: Sep 11, 2019
 *      Author: tbmnxvmuser
 */

#ifndef PAYDAYTRANSACTION_H_
#define PAYDAYTRANSACTION_H_

#include "Transaction.h"
#include "PayrollDatabase.h"
#include <vector>
#include <map>
#include <memory>

using namespace std;

namespace Payroll {

class PaydayTransaction : public Transaction {
private:
	Date payDate;
	map<int, shared_ptr<Paycheck>> paychecks;

public:
	PaydayTransaction(Date payDate) : payDate{payDate} {}

	void Execute() {
		vector<int> ids;
		vector<int>::iterator it;
		PayrollDatabase::GetAllEmployeeIds(ids);

		for (it = ids.begin(); it != ids.end(); it++)
		{
			shared_ptr<Employee> e = PayrollDatabase::GetEmployee(*it);
			if (e->IsPayday(payDate))
			{
				Date startDate = e->GetPayPeriodStartDate(payDate);
				shared_ptr<Paycheck> pc = make_shared<Paycheck>(startDate, payDate);
				paychecks[e->GetId()] = pc;
				e->Payday(pc);
			}
		}
	}

	shared_ptr<Paycheck> GetPaycheck(int empId)
	{
		if (paychecks.find(empId) != paychecks.end())
		{
			return paychecks[empId];
		} else {
			return shared_ptr<Paycheck>{nullptr};
		}
	}
};

}


#endif /* PAYDAYTRANSACTION_H_ */

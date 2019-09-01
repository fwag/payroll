/*
 * SalesReceiptTransaction.h
 *
 *  Created on: Sep 1, 2019
 *      Author: tbmnxvmuser
 */

#ifndef SALESRECEIPTTRANSACTION_H_
#define SALESRECEIPTTRANSACTION_H_

#include "Transaction.h"

namespace Payroll {

class SalesReceiptTransaction : public Transaction {
private:
	Date date;
	float amount;
	int empId;

public:
	SalesReceiptTransaction(Date date, float amount, int empId):
		date{date}, amount{amount}, empId{empId} {}

	void Execute()
	{
		unique_ptr<Employee> e = PayrollDatabase::GetEmployee(empId);

		if (e != nullptr)
		{
			shared_ptr<CommissionedClassification> cc = dynamic_pointer_cast<CommissionedClassification>(e->classification);

			if (cc != nullptr)
			{
				cc->AddSalesReceipt(SalesReceipt{date,amount});
			}
			else
			{
				runtime_error("Tried to add sales receipt to non-commissioned employee.");
			}


		} else {
			runtime_error("No such employee");
		}
	}
};

}

#endif /* SALESRECEIPTTRANSACTION_H_ */

/*
 * ChangeClassificationTransaction.h
 *
 *  Created on: Sep 8, 2019
 *      Author: tbmnxvmuser
 */

#ifndef CHANGECLASSIFICATIONTRANSACTION_H_
#define CHANGECLASSIFICATIONTRANSACTION_H_

#include "ChangeEmployeeTransaction.h"
#include <memory>

namespace Payroll {

class ChangeClassificationTransaction : public ChangeEmployeeTransaction
{
public:
	ChangeClassificationTransaction(int empId):
		ChangeEmployeeTransaction(empId)
	{}

protected:
	void Change(shared_ptr<Employee> e) final
	{
		e->SetClassification(GetClassification());
		e->SetSchedule(GetSchedule());
	}

	virtual shared_ptr<PaymentClassification> GetClassification() = 0;
	virtual shared_ptr<PaymentSchedule> GetSchedule() = 0;

};

}


#endif /* CHANGECLASSIFICATIONTRANSACTION_H_ */

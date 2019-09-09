/*
 * ChangeEmployeeTransaction.h
 *
 *  Created on: Sep 8, 2019
 *      Author: tbmnxvmuser
 */

#ifndef CHANGEEMPLOYEETRANSACTION_H_
#define CHANGEEMPLOYEETRANSACTION_H_

#include "Transaction.h"

namespace Payroll
{

class ChangeEmployeeTransaction : Transaction
{
private:
	int empId;

public:
	ChangeEmployeeTransaction(int empId) : empId{empId} {}

	void Execute()
	{
		shared_ptr<Employee> e = PayrollDatabase::GetEmployee(empId);

		if (e != nullptr)
		{
			Change(e);
		} else {
			runtime_error("No such employee");
		}
	}
protected:
	virtual void Change(shared_ptr<Employee> e) = 0;
};

}
#endif /* CHANGEEMPLOYEETRANSACTION_H_ */

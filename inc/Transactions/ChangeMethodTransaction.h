/*
 * ChangeMethodTransaction.h
 *
 *  Created on: Sep 8, 2019
 *      Author: tbmnxvmuser
 */

#ifndef CHANGEMETHODTRANSACTION_H_
#define CHANGEMETHODTRANSACTION_H_

#include "ChangeEmployeeTransaction.h"

namespace Payroll
{

class ChangeMethodTransaction : public ChangeEmployeeTransaction
{
public:
	ChangeMethodTransaction(int empId) : ChangeEmployeeTransaction(empId) {}

protected:
	void Change(shared_ptr<Employee> e) {
		e->method = GetMethod();
	}

	virtual shared_ptr<PaymentMethod> GetMethod() = 0;

};

}

#endif /* CHANGEMETHODTRANSACTION_H_ */

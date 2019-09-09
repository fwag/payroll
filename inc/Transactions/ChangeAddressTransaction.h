/*
 * ChangeAddressTransaction.h
 *
 *  Created on: Sep 8, 2019
 *      Author: tbmnxvmuser
 */

#ifndef CHANGEADDRESSTRANSACTION_H_
#define CHANGEADDRESSTRANSACTION_H_

#include <string>
#include "ChangeEmployeeTransaction.h"

namespace Payroll {

class ChangeAddressTransaction : public ChangeEmployeeTransaction
{
private:
	int empId;
	string address;

public:
	ChangeNameTransaction(int empId, string address) : ChangeEmployeeTransaction(empId), address{address} {}

protected:
	void Change(shared_ptr<Employee> e) {
		e->address = address;
	}
};

}

#endif /* CHANGEADDRESSTRANSACTION_H_ */

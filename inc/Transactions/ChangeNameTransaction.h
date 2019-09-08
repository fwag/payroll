/*
 * ChangeNameTransaction.h
 *
 *  Created on: Sep 8, 2019
 *      Author: tbmnxvmuser
 */

#ifndef CHANGENAMETRANSACTION_H_
#define CHANGENAMETRANSACTION_H_

#include "ChangeEmployeeTransaction.h"
#include <string>

using namespace std;

namespace Payroll
{

class ChangeNameTransaction : ChangeEmployeeTransaction
{
private:
	int empId;
	string name;

public:
	ChangeNameTransaction(int empId, string name) : ChangeEmployeeTransaction(empId), name{name} {}

	void Change(shared_ptr<Employee> e) {
		e->name = name;
	}

	void Execute()
	{
		ChangeEmployeeTransaction::Execute();
	}

};

}



#endif /* CHANGENAMETRANSACTION_H_ */

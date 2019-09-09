/*
 * AddEmployeeTransaction.cpp
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#include <PayrollDatabase.h>
#include "AddEmployeeTransaction.h"
#include "PaymentMethod.h"
#include "HoldMethod.h"
#include "Employee.h"
#include <memory>

namespace Payroll {

void AddEmployeeTransaction::Execute()
{
	shared_ptr<Employee> e = make_shared<Employee>(empid, name, address);
	e->SetClassification(MakeClassification());
	e->SetSchedule(MakeSchedule());
	e->SetMethod(make_shared<HoldMethod>());

	PayrollDatabase::AddEmployee(empid, e);
}

} /* namespace Payroll */

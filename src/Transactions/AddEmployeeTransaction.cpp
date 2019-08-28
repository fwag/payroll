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
	Employee e {empid, name, address};
	e.classification = MakeClassification();
	e.schedule = MakeSchedule();
	e.method = make_shared<HoldMethod>();

	PayrollDatabase::AddEmployee(empid, e);
}

} /* namespace Payroll */
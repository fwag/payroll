/*
 * PayrollDatabase.h
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#ifndef PAYROLLDATABASE_H_
#define PAYROLLDATABASE_H_

#include <map>
#include "Employee.h"

namespace Payroll {

class PayrollDatabase {
private:
	static std::map<int, Employee> employees;

public:
	static void AddEmployee (int id, Employee employee)
	{
		employees[id] = employee;
	}

	static Employee GetEmployee (int id) { return employees[id]; }
};

} /* namespace Payroll */

#endif /* PAYROLLDATABASE_H_ */

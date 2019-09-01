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
#include <memory>
using namespace std;

namespace Payroll {

class PayrollDatabase {
private:
	static std::map<int, Employee> employees;

public:
	static void AddEmployee (int id, Employee employee)
	{
		employees[id] = employee;
	}

	static unique_ptr<Employee> GetEmployee (int id) {
		if (employees.find(id) != employees.end())
		{
			return unique_ptr<Employee>(new Employee{employees[id]});
		} else {
			return unique_ptr<Employee>{nullptr};
		}
	}

	static void DeleteEmployee(int id) { employees.erase(id); }
};

} /* namespace Payroll */

#endif /* PAYROLLDATABASE_H_ */

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
	static std::map<int, shared_ptr<Employee>> unionMembers;

public:
	static void AddEmployee (int id, Employee e)
	{
		employees[id] = e;
	}

	static shared_ptr<Employee> GetEmployee (int id) {
		if (employees.find(id) != employees.end())
		{
			return shared_ptr<Employee>(new Employee{employees[id]});
		} else {
			return shared_ptr<Employee>{nullptr};
		}
	}

	static void DeleteEmployee(int id) { employees.erase(id); }

	static void AddUnionMember(int id, shared_ptr<Employee> e)
	{
		unionMembers[id] = e;
	}

	static shared_ptr<Employee> GetUnionMember (int id) {
		if (unionMembers.find(id) != unionMembers.end())
		{
			return unionMembers[id];
		} else {
			return shared_ptr<Employee>{nullptr};
		}
	}
};

} /* namespace Payroll */

#endif /* PAYROLLDATABASE_H_ */

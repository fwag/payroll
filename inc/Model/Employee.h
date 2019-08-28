/*
 * Employee.h
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <string>
#include <memory>

#include "PaymentClassification.h"
#include "PaymentSchedule.h"
#include "PaymentMethod.h"

using namespace std;

namespace Payroll {

class Employee {
public:
	int id;
	string name;
	string address;


	Employee() :
		id{-1},
		name{""},
		address{""}
	{}

	Employee(int id, string name, string address) :
		id{id},
		name{name},
		address{address}
	{}

	shared_ptr<PaymentClassification> classification;
	shared_ptr<PaymentSchedule> schedule;
	shared_ptr<PaymentMethod> method;

	Employee& operator=(const Payroll::Employee& e)
	{
		id = e.id;
		name = e.name;
		address = e.address;
		classification = std::move(e.classification);
		schedule = std::move(e.schedule);
		method = std::move(e.method);

		return *this;
	}
};

} /* namespace Payroll */

#endif /* EMPLOYEE_H_ */

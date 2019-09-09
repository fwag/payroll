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
#include "Affiliation.h"

using namespace std;

namespace Payroll {

class Employee {
private:
	int id;
	string name;
	string address;
	shared_ptr<PaymentClassification> classification;
	shared_ptr<PaymentSchedule> schedule;
	shared_ptr<PaymentMethod> method;
	shared_ptr<Affiliation> affiliation;

public:

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

	int GetId() { return id; }
	string GetName() { return name; }
	string GetAddress() { return address; }
	shared_ptr<PaymentClassification> GetClassification() { return this->classification; }
	shared_ptr<PaymentSchedule> GetSchedule() { return this->schedule; }
	shared_ptr<PaymentMethod> GetMethod() { return this->method; }
	shared_ptr<Affiliation> GetAffiliation() { return this->affiliation; }

	void SetName(string name) { this->name = name; }
	void SetAddress(string address) { this->address = address; }
	void SetClassification(shared_ptr<PaymentClassification> classification) { this->classification = classification; }
	void SetSchedule(shared_ptr<PaymentSchedule> schedule) { this->schedule = schedule; }
	void SetMethod(shared_ptr<PaymentMethod> method) { this->method = method; }
	void SetAffiliation(shared_ptr<Affiliation> affiliation) { this->affiliation = affiliation; }


	/*Employee& operator=(const Payroll::Employee& e)
	{
		id = e.id;
		name = e.name;
		address = e.address;
		classification = e.classification;
		schedule = e.schedule;
		method = e.method;
		affiliation = e.affiliation;

		return *this;
	}*/
};

} /* namespace Payroll */

#endif /* EMPLOYEE_H_ */

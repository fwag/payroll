/*
 * AddSalariedEmployee.h
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#ifndef ADDSALARIEDEMPLOYEE_H_
#define ADDSALARIEDEMPLOYEE_H_

#include <string>
#include <memory>

#include "PaymentClassification.h"
#include "PaymentSchedule.h"
#include "AddEmployeeTransaction.h"
#include "SalariedClassification.h"
#include "MonthlySchedule.h"

using namespace std;

namespace Payroll {

class AddSalariedEmployee : public AddEmployeeTransaction {
private:
	float salary;

public:
	AddSalariedEmployee(int id, string name, string address, float salary) :
			AddEmployeeTransaction(id, name, address), salary { salary } {
	}

	~AddSalariedEmployee() {}
protected:
	shared_ptr<PaymentClassification> MakeClassification() {
		return make_shared<SalariedClassification>(salary);
	}

	shared_ptr<PaymentSchedule> MakeSchedule() {
		return make_shared<MonthlySchedule>();
	}
};

} /* namespace Payroll */

#endif /* ADDSALARIEDEMPLOYEE_H_ */

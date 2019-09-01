/*
 * AddHourlyEmployee.h
 *
 *  Created on: Sep 1, 2019
 *      Author: tbmnxvmuser
 */

#ifndef ADDHOURLYEMPLOYEE_H_
#define ADDHOURLYEMPLOYEE_H_

#include "AddEmployeeTransaction.h"
#include "HourlyClassification.h"
#include "WeeklySchedule.h"

#include <string>
#include <memory>

using namespace std;

namespace Payroll {

class AddHourlyEmployee : public AddEmployeeTransaction
{
private:
	float hourlyRate;

public:
	AddHourlyEmployee(int id, string name, string address, float hourlyRate) :
		AddEmployeeTransaction(id, name, address), hourlyRate { hourlyRate } {
		}

protected:
	shared_ptr<PaymentClassification> MakeClassification() {
		return make_shared<HourlyClassification>(hourlyRate);
	}

	shared_ptr<PaymentSchedule> MakeSchedule() {
		return make_shared<WeeklySchedule>();
	}
};

}
#endif /* ADDHOURLYEMPLOYEE_H_ */

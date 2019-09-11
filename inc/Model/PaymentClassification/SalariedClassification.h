/*
 * SalariedClassification.h
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#ifndef SALARIEDCLASSIFICATION_H_
#define SALARIEDCLASSIFICATION_H_

#include "PaymentClassification.h"
#include "Paycheck.h"

namespace Payroll {

class SalariedClassification : public PaymentClassification {
private:
	float salary;

public:
	SalariedClassification(float salary) : salary{salary} {};

	float CalculatePay (shared_ptr<Paycheck> paycheck);
	float GetSalary() { return salary; }
};

} /* namespace Payroll */

#endif /* SALARIEDCLASSIFICATION_H_ */

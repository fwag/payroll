/*
 * SalariedClassification.h
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#ifndef SALARIEDCLASSIFICATION_H_
#define SALARIEDCLASSIFICATION_H_

#include "PaymentClassification.h"
#include "Date.h"

namespace Payroll {

class SalariedClassification : public PaymentClassification {
private:
	float salary;

public:
	SalariedClassification(float salary) : salary{salary} {};

	float CalculatePay (Date date);
	float GetSalary() { return salary; }
};

} /* namespace Payroll */

#endif /* SALARIEDCLASSIFICATION_H_ */

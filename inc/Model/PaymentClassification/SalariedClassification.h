/*
 * SalariedClassification.h
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#ifndef SALARIEDCLASSIFICATION_H_
#define SALARIEDCLASSIFICATION_H_

#include "PaymentClassification.h"

namespace Payroll {

class SalariedClassification : public PaymentClassification {
public:
	SalariedClassification(float salary) : salary{salary} {};

	float CalculatePay (time_t date);

	float salary;

};

} /* namespace Payroll */

#endif /* SALARIEDCLASSIFICATION_H_ */

/*
 * SalariedClassification.cpp
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#include "SalariedClassification.h"

namespace Payroll {

float SalariedClassification::CalculatePay(shared_ptr<Paycheck> paycheck)
{
	(void)paycheck;

	return salary;
}

} /* namespace Payroll */

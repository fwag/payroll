/*
 * SalariedClassification.cpp
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#include "CommissionedClassification.h"

namespace Payroll {

float CommissionedClassification::CalculatePay(Paycheck paycheck)
{
	vector<SalesReceipt>::iterator it;
	float salesTotal = 0.0;

	for (it = salesReceipts.begin(); it != salesReceipts.end(); it++)
	{
		if (paycheck.IsInPayPeriod((*it).GetDate()))
		{
			salesTotal += (*it).GetAmount();
		}
	}

	return salary+(salesTotal*commissionRate*0.01);
}

} /* namespace Payroll */

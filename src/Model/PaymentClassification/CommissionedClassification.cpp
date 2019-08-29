/*
 * SalariedClassification.cpp
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#include "CommissionedClassification.h"

namespace Payroll {

float CommissionedClassification::CalculatePay(Date date)
{
	vector<SalesReceipt>::iterator it;
	float salesTotal = 0.0;
	tm *tcDate;
	tm *payDate = date.GetTimeinfo();

	for (it = salesReceipts.begin(); it != salesReceipts.end(); it++)
	{
		tcDate = (*it).GetDate().GetTimeinfo();
		if (tcDate->tm_mday >= payDate->tm_mday)
		{
			salesTotal += (*it).GetAmount();
		}
	}

	return salary+(salesTotal*commissionRate*0.01);
}

} /* namespace Payroll */

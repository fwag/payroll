/*
 * SalariedClassification.cpp
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#include "CommissionedClassification.h"
#include <algorithm>

namespace Payroll {

float CommissionedClassification::CalculatePay(shared_ptr<Paycheck> paycheck)
{
	vector<SalesReceipt>::iterator it;
	float salesTotal = 0.0;

	for (it = salesReceipts.begin(); it != salesReceipts.end(); it++)
	{
		if (paycheck->IsInPayPeriod((*it).GetDate()))
		{
			salesTotal += (*it).GetAmount();
		}
	}

	return salary+(salesTotal*commissionRate*0.01);
}

void CommissionedClassification::AddSalesReceipt (SalesReceipt sr)
{
	salesReceipts.push_back(sr);
}

unique_ptr<SalesReceipt> CommissionedClassification::GetSalesReceipt (Date date)
{
	vector<SalesReceipt>::iterator it;
	it = find_if(salesReceipts.begin(), salesReceipts.end(), [&date](SalesReceipt sr){
		return date == sr.GetDate();
	});

	if (it == salesReceipts.end()) return unique_ptr<SalesReceipt>{nullptr};

	return unique_ptr<SalesReceipt>(new SalesReceipt{*it});
}

} /* namespace Payroll */

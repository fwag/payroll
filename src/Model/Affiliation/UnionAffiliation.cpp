/*
 * UnionAffiliation.cpp
 *
 *  Created on: Sep 1, 2019
 *      Author: tbmnxvmuser
 */

#include "UnionAffiliation.h"
#include <algorithm>
#include "Date.h"

namespace Payroll
{

void UnionAffiliation::AddServiceCharge(ServiceCharge sc)
{
	serviceCharges.push_back(sc);
}

unique_ptr<ServiceCharge> UnionAffiliation::GetServiceCharge(Date date)
{
	vector<ServiceCharge>::iterator it;
	it = find_if(serviceCharges.begin(), serviceCharges.end(), [&date](ServiceCharge sc){
		return date == sc.GetDate();
	});

	if (it == serviceCharges.end()) return unique_ptr<ServiceCharge>{nullptr};

	return unique_ptr<ServiceCharge>(new ServiceCharge{*it});
}

int UnionAffiliation::NumberOfFridaysInPayPeriod(Date payPeriodStart, Date payPeriodEnd)
{
	int fridays = 0;
	for (Date day = payPeriodStart;	day <= payPeriodEnd; day = day.AddDays(1))
	{
		if (day.GetDayOfWeek() == DayOfWeek::Friday)
			fridays++;
	}
	return fridays;
}

float UnionAffiliation::CalculateDeductions(shared_ptr<Paycheck> paycheck)
{
	double totalDues = 0;

	int fridays = NumberOfFridaysInPayPeriod(paycheck->PayPeriodStartDate(), paycheck->PayPeriodEndDate());
	totalDues = dues * fridays;

	vector<ServiceCharge>::iterator it;
	for(it = serviceCharges.begin(); it != serviceCharges.end(); it++)
	{
		if(paycheck->IsInPayPeriod((*it).GetDate()))
			totalDues += (*it).GetAmount();
	}

	return totalDues;
}

}


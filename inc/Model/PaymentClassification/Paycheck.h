/*
 * Paycheck.h
 *
 *  Created on: Aug 30, 2019
 *      Author: tbmnxvmuser
 */

#ifndef PAYCHECK_H_
#define PAYCHECK_H_

#include "Date.h"
#include <map>
#include <string>

namespace Payroll
{

class Paycheck
{
private:
	Date payDate;
	Date payPeriodStartDate;
	float grossPay;
	float deductions;
	float netPay;
	map<string, string> fields;

public:
	Paycheck(Date payPeriodStartDate, Date payDate) : payDate{payDate},
        payPeriodStartDate{payPeriodStartDate}
	{}

    Date PayPeriodStartDate() { return payPeriodStartDate; }
    Date PayPeriodEndDate() { return payDate; }

    bool IsInPayPeriod (Date theDate)
    {
        return (theDate >= PayPeriodStartDate()) && (theDate <= PayPeriodEndDate());
    }

    Date GetPaydate() { return payDate; }

    float GetGrossPay() { return grossPay; }
    void SetGrossPay(float grossPay) { this->grossPay = grossPay; }

    float GetDeductions() { return deductions; }
    void SetDeductions(float deductions) { this->deductions = deductions; }

    float GetNetPay() { return netPay; }
    void SetNetPay(float netPay) { this->netPay = netPay; }

    void SetField(string fieldName, string value)
	{
		fields[fieldName] = value;
	}

    string GetField(string fieldName)
	{
		return fields[fieldName];
	}
};

}

#endif /* PAYCHECK_H_ */

/*
 * Paycheck.h
 *
 *  Created on: Aug 30, 2019
 *      Author: tbmnxvmuser
 */

#ifndef PAYCHECK_H_
#define PAYCHECK_H_

#include "Date.h"

namespace Payroll
{

class Paycheck
{
private:
	Date payDate;
	Date payPeriodStartDate;

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
};

}

#endif /* PAYCHECK_H_ */

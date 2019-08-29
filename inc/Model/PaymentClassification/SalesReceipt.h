/*
 * SalesReceipt.h
 *
 *  Created on: Aug 29, 2019
 *      Author: tbmnxvmuser
 */

#ifndef SALESRECEIPT_H_
#define SALESRECEIPT_H_

#include <ctime>
#include "Date.h"

namespace Payroll
{

class SalesReceipt {
private:
	Date date;
	float amount;
public:
	SalesReceipt(Date date, float amount) :
		date{date}, amount{amount}
		{}

	Date GetDate() { return date; }
	float GetAmount() { return amount; }
};

}

#endif /* SALESRECEIPT_H_ */

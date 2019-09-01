/*
 * ServiceCharge.h
 *
 *  Created on: Sep 1, 2019
 *      Author: tbmnxvmuser
 */

#ifndef SERVICECHARGE_H_
#define SERVICECHARGE_H_

namespace Payroll
{
class ServiceCharge {
private:
	Date date;
	float amount;
public:
	ServiceCharge(Date date, float amount) :
		date{date}, amount{amount}
		{}

	Date GetDate() { return date; }
	float GetAmount() { return amount; }
};
}



#endif /* SERVICECHARGE_H_ */

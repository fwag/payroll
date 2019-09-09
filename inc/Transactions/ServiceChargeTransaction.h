/*
 * ServiceChargeTransaction.h
 *
 *  Created on: Sep 8, 2019
 *      Author: tbmnxvmuser
 */

#ifndef SERVICECHARGETRANSACTION_H_
#define SERVICECHARGETRANSACTION_H_

#include "Transaction.h"

namespace Payroll
{

class ServiceChargeTransaction : Transaction
{
private:
	int membId;
	Date date;
	float amount;
public:
	ServiceChargeTransaction(int membId, Date date, float amount):
		membId{membId}, date{date}, amount{amount}
		{}

	void Execute()
	{
		shared_ptr<Employee> e = PayrollDatabase::GetUnionMember(membId);

		if (e != nullptr)
		{
			shared_ptr<UnionAffiliation> ua = dynamic_pointer_cast<UnionAffiliation>(e->GetAffiliation());
			if (ua != nullptr)
			{
				ServiceCharge sc{date, amount};
				ua->AddServiceCharge(sc);
			} else {
				runtime_error("Tried to add service charge to non union employee");
			}
		} else {
			runtime_error("No such employee");
		}
	}


};

}


#endif /* SERVICECHARGETRANSACTION_H_ */

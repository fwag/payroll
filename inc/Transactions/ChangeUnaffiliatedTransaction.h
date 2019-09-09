/*
 * ChangeUnaffiliatedTransaction.h
 *
 *  Created on: Sep 9, 2019
 *      Author: tbmnxvmuser
 */

#ifndef CHANGEUNAFFILIATEDTRANSACTION_H_
#define CHANGEUNAFFILIATEDTRANSACTION_H_

#include "ChangeAffiliationTransaction.h"
#include "Affiliation.h"
#include "NoAffiliation.h"
#include <memory>

namespace Payroll
{

class ChangeUnaffiliatedTransaction : public ChangeAffiliationTransaction
{
private:
	int memId;

public:
	ChangeUnaffiliatedTransaction(int empId, int memId):
		ChangeAffiliationTransaction(empId), memId{memId}
	{}

protected:
	void RecordMembership(shared_ptr<Employee> e)
	{
		shared_ptr<UnionAffiliation> ua = dynamic_pointer_cast<UnionAffiliation>(e->affiliation);
		if (ua != nullptr)
		{
			PayrollDatabase::RemoveUnionMember(ua->GetMemberId());
		}
	}

	shared_ptr<Affiliation> GetAffiliation()
	{
		return make_shared<NoAffiliation>();
	}
};

}

#endif /* CHANGEUNAFFILIATEDTRANSACTION_H_ */

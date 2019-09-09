/*
 * ChangeMemberTransaction.h
 *
 *  Created on: Sep 9, 2019
 *      Author: tbmnxvmuser
 */

#ifndef CHANGEMEMBERTRANSACTION_H_
#define CHANGEMEMBERTRANSACTION_H_

#include "ChangeAffiliationTransaction.h"

namespace Payroll
{

class ChangeMemberTransaction : public ChangeAffiliationTransaction
{
private:
	int memId;
	float dues;

public:
	ChangeMemberTransaction(int empId, int memId, float dues):
		ChangeAffiliationTransaction(empId), memId{memId}, dues{dues} {}

protected:
	void RecordMembership (shared_ptr<Employee> e) final
	{
		PayrollDatabase::AddUnionMember(memId, e);
	}

	shared_ptr<Affiliation> GetAffiliation()
	{
		return make_shared<UnionAffiliation>(memId,dues);
	}
};

}

#endif /* CHANGEMEMBERTRANSACTION_H_ */

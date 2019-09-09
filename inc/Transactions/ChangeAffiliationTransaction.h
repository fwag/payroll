/*
 * ChangeAffiliationTransaction.h
 *
 *  Created on: Sep 9, 2019
 *      Author: tbmnxvmuser
 */

#ifndef CHANGEAFFILIATIONTRANSACTION_H_
#define CHANGEAFFILIATIONTRANSACTION_H_

namespace Payroll
{

class ChangeAffiliationTransaction : public ChangeEmployeeTransaction
{
public:
	ChangeAffiliationTransaction(int empId) : ChangeEmployeeTransaction(empId) {};

protected:
	void Change (shared_ptr<Employee> e)
	{
		RecordMembership(e);
		shared_ptr<Affiliation> af = GetAffiliation();
		e->affiliation = af;
	}

	virtual shared_ptr<Affiliation> GetAffiliation() = 0;
	virtual void RecordMembership (shared_ptr<Employee> e) = 0;
};

}

#endif /* CHANGEAFFILIATIONTRANSACTION_H_ */

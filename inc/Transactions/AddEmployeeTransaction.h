/*
 * AddEmployeeTransaction.h
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#ifndef ADDEMPLOYEETRANSACTION_H_
#define ADDEMPLOYEETRANSACTION_H_

#include "Transaction.h"
#include <string>

using namespace std;

#include "PaymentClassification.h"
#include "PaymentSchedule.h"
#include <memory>

namespace Payroll {

class AddEmployeeTransaction : public Transaction {
private:
	int empid;
	string name;
	string address;

public:
	AddEmployeeTransaction(int empid, string name, string address) :
		empid {empid},
		name {name},
		address {address}
	{}
	//virtual ~AddEmployeeTransaction();

	void Execute() final;
protected:
	virtual shared_ptr<PaymentClassification> MakeClassification() = 0;
	virtual shared_ptr<PaymentSchedule> MakeSchedule() = 0;


};

} /* namespace Payroll */

#endif /* ADDEMPLOYEETRANSACTION_H_ */

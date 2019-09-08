/*
 * ChangeDirectTransaction.h
 *
 *  Created on: Sep 8, 2019
 *      Author: tbmnxvmuser
 */

#ifndef CHANGEDIRECTTRANSACTION_H_
#define CHANGEDIRECTTRANSACTION_H_

#include <string>
#include "ChangeMethodTransaction.h"
#include "DirectMethod.h"
#include <memory>
#include "PaymentMethod.h"

using namespace std;

namespace Payroll
{

class ChangeDirectTransaction : public ChangeMethodTransaction
{
private:
	string bank;
	string account;

public:
	ChangeDirectTransaction(int empId, string bank, string account) :
		 ChangeMethodTransaction(empId), bank{bank}, account{account} {}


	shared_ptr<PaymentMethod> GetMethod()
	{
		return make_shared<DirectMethod>(bank,account);
	}
};

}

#endif /* CHANGEDIRECTTRANSACTION_H_ */

/*
 * DirectMethod.h
 *
 *  Created on: Sep 8, 2019
 *      Author: tbmnxvmuser
 */

#ifndef DIRECTMETHOD_H_
#define DIRECTMETHOD_H_

#include <string>
#include "Paycheck.h"

using namespace std;

namespace Payroll {

class DirectMethod : public PaymentMethod {
private:
	string bank;
	string account;

public:
	DirectMethod(string bank, string account) :
		bank{bank}, account{account} {}

	string GetBank() { return bank; }
	string GetAccount() { return account; }

	void Pay(shared_ptr<Paycheck> paycheck) final {}
};

}




#endif /* DIRECTMETHOD_H_ */

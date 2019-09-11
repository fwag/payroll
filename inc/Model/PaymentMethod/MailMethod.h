/*
 * MailMethod.h
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#ifndef MAILMETHOD_H_
#define MAILMETHOD_H_

#include "PaymentMethod.h"
#include <string>
#include "Paycheck.h"

using namespace std;

namespace Payroll {

class MailMethod : public PaymentMethod {
public:
	MailMethod(string address) : address{address} {}
	void Pay(shared_ptr<Paycheck> paycheck) final {}
	string address;

};

} /* namespace Payroll */

#endif /* MAILMETHOD_H_ */

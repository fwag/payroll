/*
 * ChangeMailTransaction.h
 *
 *  Created on: Sep 8, 2019
 *      Author: tbmnxvmuser
 */

#ifndef CHANGEMAILTRANSACTION_H_
#define CHANGEMAILTRANSACTION_H_

#include <string>
#include <memory>

using namespace std;

namespace Payroll
{

class ChangeMailTransaction : public ChangeMethodTransaction
{
private:
	string mail;

public:
	ChangeMailTransaction(int empId, string mail) :
		 ChangeMethodTransaction(empId), mail{mail} {}


	shared_ptr<PaymentMethod> GetMethod()
	{
		return make_shared<MailMethod>(mail);
	}
};

}


#endif /* CHANGEMAILTRANSACTION_H_ */

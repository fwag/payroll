/*
 * Transaction.h
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#ifndef TRANSACTION_H_
#define TRANSACTION_H_

namespace Payroll {

class Transaction {
public:
	virtual void Execute() = 0;
	//virtual ~Transaction();
};

} /* namespace Payroll */

#endif /* TRANSACTION_H_ */

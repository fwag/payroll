/*
 * DeleteEmployeeTransaction.h
 *
 *  Created on: Sep 1, 2019
 *      Author: tbmnxvmuser
 */

#ifndef DELETEEMPLOYEETRANSACTION_H_
#define DELETEEMPLOYEETRANSACTION_H_

#include "Transaction.h"

namespace Payroll
{
class DeleteEmployeeTransaction : public Transaction
{
private :
	int id;


public:
	DeleteEmployeeTransaction(int id) : id{id} {}

	void Execute() {
		PayrollDatabase::DeleteEmployee(id);
	}
};
}

#endif /* DELETEEMPLOYEETRANSACTION_H_ */

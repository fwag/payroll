/*
 * AddCommissionedEmployee.h
 *
 *  Created on: Sep 1, 2019
 *      Author: tbmnxvmuser
 */

#ifndef ADDCOMMISSIONEDEMPLOYEE_H_
#define ADDCOMMISSIONEDEMPLOYEE_H_

#include "AddEmployeeTransaction.h"
#include "CommissionedClassification.h"
#include "BiweeklySchedule.h"

#include <string>
#include <memory>


namespace Payroll {

class AddCommissionedEmployee : public AddEmployeeTransaction
{
private:
	float salary;
	float commissionedRate;

public:
	AddCommissionedEmployee(int id, string name, string address, float salary, float commissionedRate) :
		AddEmployeeTransaction(id, name, address), salary { salary }, commissionedRate {commissionedRate}{
		}

protected:
	shared_ptr<PaymentClassification> MakeClassification() {
		return make_shared<CommissionedClassification>(salary, commissionedRate);
	}

	shared_ptr<PaymentSchedule> MakeSchedule() {
		return make_shared<BiweeklySchedule>();
	}
};

}




#endif /* ADDCOMMISSIONEDEMPLOYEE_H_ */

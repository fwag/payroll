/*
 * SalariedClassification.h
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#ifndef COMMISSIONEDCLASSIFICATION_H_
#define COMMISSIONEDCLASSIFICATION_H_

#include "PaymentClassification.h"
#include "SalesReceipt.h"
#include <vector>
#include "Date.h"

using namespace std;

namespace Payroll {

class CommissionedClassification : public PaymentClassification {
private:
	float salary;
	float commissionRate;

	vector<SalesReceipt> salesReceipts;

public:
	CommissionedClassification(float salary, float commissionRate) :
		salary{salary},
		commissionRate{commissionRate}
	{}

	float CalculatePay (Paycheck paycheck);



};

} /* namespace Payroll */

#endif /* COMMISSIONEDCLASSIFICATION_H_ */

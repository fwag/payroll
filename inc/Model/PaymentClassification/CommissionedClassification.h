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
#include "SalesReceipt.h"
#include <memory>

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

	void AddSalesReceipt (SalesReceipt sr);
	unique_ptr<SalesReceipt> GetSalesReceipt (Date date);

};

} /* namespace Payroll */

#endif /* COMMISSIONEDCLASSIFICATION_H_ */

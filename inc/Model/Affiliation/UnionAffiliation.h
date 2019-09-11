/*
 * UnionAffiliation.h
 *
 *  Created on: Sep 1, 2019
 *      Author: tbmnxvmuser
 */

#ifndef UNIONAFFILIATION_H_
#define UNIONAFFILIATION_H_

#include <vector>
#include <memory>
#include "Affiliation.h"
#include "ServiceCharge.h"
#include <iostream>

using namespace std;

namespace Payroll {

class UnionAffiliation : public Affiliation {
private:
	int memberId;
	float dues;

	vector<ServiceCharge> serviceCharges;

	int NumberOfFridaysInPayPeriod(Date payPeriodStart, Date payPeriodEnd);

public:
	UnionAffiliation (int mId, float dues) :
		memberId{mId}, dues{dues}
		{}

	UnionAffiliation() : memberId{-1}, dues{0.0} {}

	int GetMemberId() { return memberId; }
	float GetDues() { return dues; }

	void AddServiceCharge(ServiceCharge sc);
	unique_ptr<ServiceCharge> GetServiceCharge(Date date);

	float CalculateDeductions(shared_ptr<Paycheck> paycheck) final;
};
}



#endif /* UNIONAFFILIATION_H_ */

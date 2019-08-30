/*
 * HourlyClassification.h
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#ifndef HOURLYCLASSIFICATION_H_
#define HOURLYCLASSIFICATION_H_

#include "PaymentClassification.h"
#include "TimeCard.h"
#include <vector>
#include <ctime>
#include "Paycheck.h"
#include "Date.h"

using namespace std;

namespace Payroll {

class HourlyClassification : public PaymentClassification {
private:
	float hourlyRate;
	vector<TimeCard> timecards;

	float CalculateDailyRate (int hours);


public:
	HourlyClassification(float hourlyRate) :
		hourlyRate{hourlyRate}
	{}

	float CalculatePay (Paycheck paycheck) final;
	void AddTimeCard(TimeCard card);
	TimeCard GetTimeCard(Date date);
};

} /* namespace Payroll */

#endif /* HOURLYCLASSIFICATION_H_ */

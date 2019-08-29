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

	float CalculatePay (time_t date) final;
	void AddTimeCard(TimeCard card);
	TimeCard GetTimeCard(time_t date);
};

} /* namespace Payroll */

#endif /* HOURLYCLASSIFICATION_H_ */

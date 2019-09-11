/*
 * Affiliation.h
 *
 *  Created on: Sep 1, 2019
 *      Author: tbmnxvmuser
 */

#ifndef AFFILIATION_H_
#define AFFILIATION_H_

#include "Paycheck.h"

namespace Payroll {

class Affiliation {
public:
	virtual float CalculateDeductions(shared_ptr<Paycheck> paycheck) = 0;
};
}




#endif /* AFFILIATION_H_ */

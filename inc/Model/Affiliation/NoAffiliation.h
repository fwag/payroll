/*
 * NoAffiliation.h
 *
 *  Created on: Sep 9, 2019
 *      Author: tbmnxvmuser
 */

#ifndef NOAFFILIATION_H_
#define NOAFFILIATION_H_

#include "Affiliation.h"

namespace Payroll
{
	class NoAffiliation : public Affiliation {
	public:
		NoAffiliation() {}
		float CalculateDeductions(shared_ptr<Paycheck> paycheck) {
			(void)paycheck;
			return 0.0f;
		}

	};
}

#endif /* NOAFFILIATION_H_ */

/*
 * PayrollDatabase.cpp
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#include "PayrollDatabase.h"

namespace Payroll {

std::map<int, shared_ptr<Employee>> PayrollDatabase::employees = {};
std::map<int, shared_ptr<Employee>> PayrollDatabase::unionMembers = {};


} /* namespace Payroll */

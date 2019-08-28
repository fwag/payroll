//============================================================================
// Name        : Payroll.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "Employee.h"
#include "AddSalariedEmployee.h"
#include "PayrollDatabase.h"
#include "PaymentClassification.h"
#include "PaymentSchedule.h"
#include "PaymentMethod.h"
#include "HoldMethod.h"
#include "MailMethod.h"
#include "MonthlySchedule.h"

using namespace Payroll;

TEST_CASE( "Payroll - add salaried employee", "[simple-add-salaried-employee]" )
{
	int empId = 1;
	AddSalariedEmployee t{empId, "Bob", "Home", 1000.0};
	t.Execute();

	Employee e = PayrollDatabase::GetEmployee(empId);
	REQUIRE("Bob" == e.name);

	//PaymentClassification pc = e.Classification;
	//REQUIRE(pc is SalariedClassification);

	bool failedConv = false;
	shared_ptr<SalariedClassification> sc = dynamic_pointer_cast<SalariedClassification>(e.classification);
	if (sc != nullptr)
		REQUIRE(1000.00 == sc->salary);
	else
		failedConv = true;
	REQUIRE(false == failedConv);

	failedConv = false;
	shared_ptr<MonthlySchedule> ps = dynamic_pointer_cast<MonthlySchedule>(e.schedule);
	if (ps == nullptr)
	{
		failedConv = true;
	}
	REQUIRE(false == failedConv);

	failedConv = false;
	shared_ptr<HoldMethod> pm = dynamic_pointer_cast<HoldMethod>(e.method);
	if (pm == nullptr)
	{
		failedConv = true;
	}

	REQUIRE(false == failedConv);
}

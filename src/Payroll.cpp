//============================================================================
// Name        : Payroll.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <iostream>
#include <ctime>

#include "Employee.h"
#include "AddSalariedEmployee.h"
#include "PayrollDatabase.h"
#include "PaymentClassification.h"
#include "PaymentSchedule.h"
#include "PaymentMethod.h"
#include "HoldMethod.h"
#include "MailMethod.h"
#include "MonthlySchedule.h"
#include "HourlyClassification.h"
#include "catch.hpp"

using namespace Payroll;
using namespace std;

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

TEST_CASE( "Payroll - test hourly classification", "[simple-hourly-classification]" )
{
	   tm* timeinfo;
	   time_t rawtime;

	   time ( &rawtime );
	   timeinfo = localtime ( &rawtime );
	   timeinfo->tm_year = 2019-1900;
	   timeinfo->tm_mon = 8 -1;
	   timeinfo->tm_mday = 29;

	   rawtime = mktime(timeinfo);

	   TimeCard tc {rawtime, 12};

	   HourlyClassification hc {11};
	   hc.AddTimeCard(tc);

	   TimeCard tc2 = hc.GetTimeCard(rawtime);

	   REQUIRE (tc.GetDate() == tc2.GetDate());

	   REQUIRE (hc.CalculatePay(rawtime) == 154.0);
}

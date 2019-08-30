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
#include "WeeklySchedule.h"
#include "MonthlySchedule.h"
#include "HourlyClassification.h"
#include "catch.hpp"
#include "Date.h"

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
		REQUIRE(1000.00 == sc->GetSalary());
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
	   Date date("30/08/2019");
	   TimeCard tc {date, 12};

	   HourlyClassification hc {11};
	   hc.AddTimeCard(tc);

	   TimeCard tc2 = hc.GetTimeCard(date);

	   REQUIRE (tc.GetDate() == tc2.GetDate());

	   WeeklySchedule ws;
	   Date startDate = ws.GetPayPeriodStartDate(date);
	   REQUIRE (date >= startDate);

	   Paycheck pc{startDate, date};
	   REQUIRE (hc.CalculatePay(pc) == 154.0);
}

TEST_CASE ( "MonthlySchedule - test monthly schedule utility", "[simple-monthly-schedule]" )
{
	Date date1{"30/08/2019"};
	MonthlySchedule ms;

	REQUIRE (ms.IsPayday(date1) == false);

	Date date2{"31/08/2019"};
	REQUIRE (ms.IsPayday(date2) == true);

	Date startDate = ms.GetPayPeriodStartDate(date2);
	Date date3{"01/08/2019"};
	REQUIRE (startDate == date3);
}

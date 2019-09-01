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
#include "AddCommissionedEmployee.h"
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
#include "DeleteEmployeeTransaction.h"
#include "AddHourlyEmployee.h"
#include "TimeCardTransaction.h"
#include "SalesReceiptTransaction.h"

using namespace Payroll;
using namespace std;

TEST_CASE( "Payroll - add salaried employee", "[simple-add-salaried-employee]" )
{
	int empId = 1;
	AddSalariedEmployee t{empId, "Bob", "Home", 1000.0};
	t.Execute();

	unique_ptr<Employee> e = PayrollDatabase::GetEmployee(empId);
	REQUIRE("Bob" == e->name);

	//PaymentClassification pc = e.Classification;
	//REQUIRE(pc is SalariedClassification);

	shared_ptr<SalariedClassification> sc = dynamic_pointer_cast<SalariedClassification>(e->classification);
	REQUIRE (sc != nullptr);
	REQUIRE(1000.00 == sc->GetSalary());

	shared_ptr<MonthlySchedule> ps = dynamic_pointer_cast<MonthlySchedule>(e->schedule);
	REQUIRE (ps != nullptr);

	shared_ptr<HoldMethod> pm = dynamic_pointer_cast<HoldMethod>(e->method);
	REQUIRE (pm != nullptr);
}

TEST_CASE( "Payroll - test hourly classification", "[simple-hourly-classification]" )
{
	   Date date("30/08/2019");
	   TimeCard tc {date, 12};

	   HourlyClassification hc {11};
	   hc.AddTimeCard(tc);

	   unique_ptr<TimeCard> tc2 = hc.GetTimeCard(date);

	   REQUIRE(tc2 != nullptr);
	   REQUIRE (tc.GetDate() == tc2->GetDate());

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

TEST_CASE ( "Delete transaction test", "[simple-delete-transaction]")
{
	int empId = 4;
	AddCommissionedEmployee t {empId, "Bill", "Home", 2500, 3.2};
	t.Execute();
	unique_ptr<Employee> e = PayrollDatabase::GetEmployee(empId);
	REQUIRE(e != nullptr);
	DeleteEmployeeTransaction dt {empId};
	dt.Execute();
	e = std::move(PayrollDatabase::GetEmployee(empId));
	REQUIRE(e == nullptr);
}

TEST_CASE ( "Time card transaction test", "[simple-timecard-transaction]" )
{
	int empId = 5;
	AddHourlyEmployee t {empId, "Bill", "Home", 15.25};
	t.Execute();
	TimeCardTransaction tct {Date{"31/07/2005"}, 8.0, empId};
	tct.Execute();
	unique_ptr<Employee> e = PayrollDatabase::GetEmployee(empId);
	REQUIRE(e != nullptr);
	shared_ptr<HourlyClassification> hc = dynamic_pointer_cast<HourlyClassification>(e->classification);
	REQUIRE(hc != nullptr);
	unique_ptr<TimeCard> tc = hc->GetTimeCard(Date{"31/07/2005"});
	REQUIRE(tc != nullptr);
	REQUIRE(8.0 == tc->GetHours());
}

TEST_CASE ( "Sales receipt transaction test", "[simple-salesreceipt-transaction]" )
{
	int empId = 6;
	AddCommissionedEmployee t {empId, "Bill", "Home", 1500.0, 15.25};
	t.Execute();
	SalesReceiptTransaction tct {Date{"31/07/2005"}, 50.0, empId};
	tct.Execute();
	unique_ptr<Employee> e = PayrollDatabase::GetEmployee(empId);
	REQUIRE(e != nullptr);
	shared_ptr<CommissionedClassification> cc = dynamic_pointer_cast<CommissionedClassification>(e->classification);
	REQUIRE(cc != nullptr);
	unique_ptr<SalesReceipt> sr = cc->GetSalesReceipt(Date{"31/07/2005"});
	REQUIRE(sr != nullptr);
	REQUIRE(50.0 == sr->GetAmount());
}

TEST_CASE ( "Service charge transaction test", "[simple-servicecharge-transaction" )
{
	int empId = 2;
	AddHourlyEmployee t	{empId, "Bill", "Home", 15.25};
	t.Execute();
	unique_ptr<Employee> e = PayrollDatabase::GetEmployee(empId);
	REQUIRE (e != nullptr);
#if 0
	UnionAffiliation af = new UnionAffiliation();
	e.Affiliation = af;
	int memberId = 86; // Maxwell Smart
	PayrollDatabase.AddUnionMember(memberId, e);
	ServiceChargeTransaction sct =
	new ServiceChargeTransaction(
	memberId, new DateTime(2005, 8, 8), 12.95);
	sct.Execute();
	ServiceCharge sc =
	af.GetServiceCharge(new DateTime(2005, 8, 8));
	Assert.IsNotNull(sc);
	Assert.AreEqual(12.95, sc.Amount, .001);
#endif
}

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
#include "UnionAffiliation.h"
#include "ServiceChargeTransaction.h"
#include "ChangeNameTransaction.h"
#include "ChangeHourlyTransaction.h"
#include "ChangeDirectTransaction.h"
#include "ChangeMemberTransaction.h"
#include "ChangeUnaffiliatedTransaction.h"
#include "PaydayTransaction.h"

using namespace Payroll;
using namespace std;

TEST_CASE( "Payroll - add salaried employee", "[simple-add-salaried-employee]" )
{
	int empId = 1;
	AddSalariedEmployee t{empId, "Bob", "Home", 1000.0};
	t.Execute();

	shared_ptr<Employee> e = PayrollDatabase::GetEmployee(empId);
	REQUIRE("Bob" == e->GetName());

	//PaymentClassification pc = e.Classification;
	//REQUIRE(pc is SalariedClassification);

	shared_ptr<PaymentClassification> pc = e->GetClassification();
	REQUIRE (pc != nullptr);

	shared_ptr<SalariedClassification> sc = dynamic_pointer_cast<SalariedClassification>(e->GetClassification());
	REQUIRE (sc != nullptr);
	REQUIRE(1000.00 == sc->GetSalary());

	shared_ptr<MonthlySchedule> ps = dynamic_pointer_cast<MonthlySchedule>(e->GetSchedule());
	REQUIRE (ps != nullptr);

	shared_ptr<HoldMethod> pm = dynamic_pointer_cast<HoldMethod>(e->GetMethod());
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

	   shared_ptr<Paycheck> pc = make_shared<Paycheck>(startDate, date);
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
	shared_ptr<Employee> e = PayrollDatabase::GetEmployee(empId);
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
	shared_ptr<Employee> e = PayrollDatabase::GetEmployee(empId);
	REQUIRE(e != nullptr);
	shared_ptr<HourlyClassification> hc = dynamic_pointer_cast<HourlyClassification>(e->GetClassification());
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
	shared_ptr<Employee> e = PayrollDatabase::GetEmployee(empId);
	REQUIRE(e != nullptr);
	shared_ptr<CommissionedClassification> cc = dynamic_pointer_cast<CommissionedClassification>(e->GetClassification());
	REQUIRE(cc != nullptr);
	unique_ptr<SalesReceipt> sr = cc->GetSalesReceipt(Date{"31/07/2005"});
	REQUIRE(sr != nullptr);
	REQUIRE(50.0 == sr->GetAmount());
}

TEST_CASE ( "Service charge transaction test", "[simple-servicecharge-transaction]" )
{
	int empId = 2;
	AddHourlyEmployee t	{empId, "Bill", "Home", 15.25};
	t.Execute();
	shared_ptr<Employee> e = PayrollDatabase::GetEmployee(empId);
	REQUIRE (e != nullptr);

	shared_ptr<UnionAffiliation> af = make_shared<UnionAffiliation>();
	e->SetAffiliation(af);
	int memberId = 86; // Maxwell Smart
	PayrollDatabase::AddUnionMember(memberId, e);

	ServiceChargeTransaction sct {memberId, Date{"08/08/2005"}, 12.95};
	sct.Execute();
	unique_ptr<ServiceCharge> sc =	af->GetServiceCharge(Date{"08/08/2005"});
	REQUIRE (sc != nullptr);
	REQUIRE(12.95f == sc->GetAmount());
}

TEST_CASE ( "Change name transaction test", "[change-name-transaction]")
{
	int empId = 2;
	AddHourlyEmployee t {empId, "Bill", "Home", 15.25};
	t.Execute();
	ChangeNameTransaction cnt {empId, "Bob"};
	cnt.Execute();
	shared_ptr<Employee> e = PayrollDatabase::GetEmployee(empId);
	REQUIRE (e != nullptr);
	REQUIRE ("Bob" == e->GetName());
}

TEST_CASE ( "Change classification to hourly", "[change-to-hourly-classification]")
{
	int empId = 15;
	AddCommissionedEmployee t (empId, "Lance", "Home", 2500, 3.2);
	t.Execute();
	ChangeHourlyTransaction cht (empId, 27.52);
	cht.Execute();
	shared_ptr<Employee> e = PayrollDatabase::GetEmployee(empId);
	REQUIRE (e != nullptr);
	shared_ptr<HourlyClassification> hc = dynamic_pointer_cast<HourlyClassification>(e->GetClassification());
	REQUIRE (hc != nullptr);
	REQUIRE(27.52f == hc->GetHourlyRate());

	shared_ptr<WeeklySchedule> ps = dynamic_pointer_cast<WeeklySchedule>(e->GetSchedule());
	REQUIRE(ps != nullptr);
}

TEST_CASE ( "Change to direct method", "[change-to-direct-method]")
{
	int empId = 5;
	AddHourlyEmployee t (empId, "Mino", "Bejing", 11.0);
	t.Execute();
	ChangeDirectTransaction cht (empId, "Goldman&Sachs", "1312321313");
	cht.Execute();
	shared_ptr<Employee> e = PayrollDatabase::GetEmployee(empId);
	REQUIRE (e != nullptr);
	shared_ptr<DirectMethod> dc = dynamic_pointer_cast<DirectMethod>(e->GetMethod());
	REQUIRE (dc != nullptr);
	REQUIRE (dc->GetBank() == "Goldman&Sachs");

}

TEST_CASE ( "Change to union member", "[change-to-union-member]" )
{
	int empId = 8;
	AddHourlyEmployee t (empId, "Bill", "Home", 15.25);
	t.Execute();
	int memberId = 7743;
	ChangeMemberTransaction cmt (empId, memberId, 99.42);
	cmt.Execute();
	shared_ptr<Employee> e = PayrollDatabase::GetEmployee(empId);
	REQUIRE (e != nullptr);
	shared_ptr<UnionAffiliation> ua = dynamic_pointer_cast<UnionAffiliation>(e->GetAffiliation());
	REQUIRE(ua != nullptr);
	REQUIRE(99.42f == ua->GetDues());
	shared_ptr<Employee> member = PayrollDatabase::GetUnionMember(memberId);
	REQUIRE (member != nullptr);
	REQUIRE (e == member);
}

TEST_CASE ( "Change to not affiliated member", "[change-to-unaffiliated-member]" )
{
	int empId = 13;
	AddHourlyEmployee t (empId, "Bill", "Home", 15.25);
	t.Execute();
	int memberId = 7745;
	ChangeMemberTransaction cmt (empId, memberId, 89.42);
	cmt.Execute();
	shared_ptr<Employee> e = PayrollDatabase::GetEmployee(empId);
	REQUIRE (e != nullptr);
	shared_ptr<UnionAffiliation> ua = dynamic_pointer_cast<UnionAffiliation>(e->GetAffiliation());
	REQUIRE(ua != nullptr);
	REQUIRE(89.42f == ua->GetDues());
	shared_ptr<Employee> member = PayrollDatabase::GetUnionMember(memberId);
	REQUIRE (member != nullptr);
	REQUIRE (e == member);
	ChangeUnaffiliatedTransaction cmt2 (empId, memberId);
	cmt2.Execute();
	shared_ptr<Employee> member2 = PayrollDatabase::GetUnionMember(memberId);
	REQUIRE (member2 == nullptr);
}


TEST_CASE ("Pay single salaried employee", "[pay-single-salaried-employee]")
{
	int empId = 23;
	AddSalariedEmployee t (empId, "Bob", "Home", 1000.00);
	t.Execute();
	Date payDate ("30/11/2001");
	PaydayTransaction pt (payDate);
	pt.Execute();
	shared_ptr<Paycheck> pc = pt.GetPaycheck(empId);
	REQUIRE(pc != nullptr);
	REQUIRE(payDate == pc->GetPaydate());
	REQUIRE(1000.0f == pc->GetGrossPay());
	//Assert.AreEqual("Hold", pc.GetField("Disposition"));
	REQUIRE(0.0f == pc->GetDeductions());
	REQUIRE(1000.0f == pc->GetNetPay());
}

TEST_CASE ("Pay single salaried employee on wrong date", "[pay-single-salaried-on-wrong-date]")
{
	int empId = 24;
	AddSalariedEmployee t (empId, "Bob", "Home", 1000.00);
	t.Execute();
	Date payDate ("29/11/2010");
	PaydayTransaction pt (payDate);
	pt.Execute();
	shared_ptr<Paycheck> pc = pt.GetPaycheck(empId);
	REQUIRE(pc == nullptr);
}

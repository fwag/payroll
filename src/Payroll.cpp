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
	REQUIRE("Hold" == pc->GetField("Disposition"));
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

void ValidateHourlyPaycheck(PaydayTransaction pt, int empid, Date payDate, float pay)
{
	shared_ptr<Paycheck> pc = pt.GetPaycheck(empid);
	REQUIRE (pc != nullptr);
	REQUIRE(payDate == pc->GetPaydate());
	REQUIRE(pay == pc->GetGrossPay());
	REQUIRE("Hold" == pc->GetField("Disposition"));
	REQUIRE(0.0f == pc->GetDeductions());
	REQUIRE(pay == pc->GetNetPay());
}

TEST_CASE("Paying single hourly employee no timecards", "[pay-single-hourly-employee-no-timecards]")
{
	int empId = 32;
	AddHourlyEmployee t (empId, "Bill", "Home", 15.25f);
	t.Execute();
	Date payDate ("09/11/2001");
	PaydayTransaction pt (payDate);
	pt.Execute();
	ValidateHourlyPaycheck(pt, empId, payDate, 0.0f);
}

TEST_CASE ("Pay single hourly employee one timecard", "[pay-single-hourly-employee-one-timecard]")
{
	int empId = 33;
	AddHourlyEmployee t (empId, "Bill", "Home", 15.25);
	t.Execute();
	Date payDate ("09/11/2001");//Friday
	TimeCardTransaction tc (payDate, 2.0, empId);
	tc.Execute();
	PaydayTransaction pt (payDate);
	pt.Execute();
	ValidateHourlyPaycheck(pt, empId, payDate, 30.5f);
}

TEST_CASE ("Pay single hourly employee overtime one timecard", "[pay-single-hourly-employee-overtime-one-timecard]")
{
	int empId = 2;
	AddHourlyEmployee t (empId, "Bill", "Home", 15.25);
	t.Execute();
	Date payDate ("09/11/2001");//Friday
	TimeCardTransaction tc (payDate, 9.0, empId);
	tc.Execute();
	PaydayTransaction pt (payDate);
	pt.Execute();
	ValidateHourlyPaycheck(pt, empId, payDate, (8 + 1.5)*15.25);
}

TEST_CASE ("Pay single hourly employee on wrong date", "[pay-single-hourly-employee-on-wrong-date]")
{
	int empId = 2;
	AddHourlyEmployee t (empId, "Bill", "Home", 15.25);
	t.Execute();
	Date payDate ("08/11/2001"); // Thursday
	TimeCardTransaction tc (payDate, 9.0, empId);
	tc.Execute();
	PaydayTransaction pt (payDate);
	pt.Execute();
	shared_ptr<Paycheck> pc = pt.GetPaycheck(empId);
	REQUIRE (pc == nullptr);
}

TEST_CASE ("Pay single hourly employee two timecards", "[pay-single-hourly-employee-two-timecards]")
{
	int empId = 2;
	AddHourlyEmployee t (empId, "Bill", "Home", 15.25);
	t.Execute();
	Date payDate ("09/11/2001");//Friday
	TimeCardTransaction tc (payDate, 2.0, empId);
	tc.Execute();
	TimeCardTransaction tc2 (payDate.AddDays(-1), 5.0,empId);
	tc2.Execute();
	PaydayTransaction pt (payDate);
	pt.Execute();
	ValidateHourlyPaycheck(pt, empId, payDate, 7*15.25);
}

TEST_CASE ("Test pay single hourly employee with timecards spanning two pay periods",
		"[test-pay-single-hourly-employee-with-timecards-spanning-two-pay-periods]")
{
	int empId = 2;
	AddHourlyEmployee t (empId, "Bill", "Home", 15.25);
	t.Execute();
	Date payDate ("09/11/2001");//Friday
	Date dateInPreviousPayPeriod ("2/11/2001");
	TimeCardTransaction tc (payDate, 2.0, empId);
	tc.Execute();
	TimeCardTransaction tc2 (dateInPreviousPayPeriod, 5.0, empId);
	tc2.Execute();
	PaydayTransaction pt (payDate);
	pt.Execute();
	ValidateHourlyPaycheck(pt, empId, payDate, 2*15.25);
}

TEST_CASE("Hourly union member service charge",
		"[hourly-union-member-service-charge]")
{
	int empId = 35;
	AddHourlyEmployee t (empId, "Bill", "Home", 15.24);
	t.Execute();
	int memberId = 7734;
	ChangeMemberTransaction cmt (empId, memberId, 9.42);
	cmt.Execute();
	Date payDate ("09/11/2001");//Friday
	ServiceChargeTransaction sct (memberId, payDate, 19.42);
	sct.Execute();
	TimeCardTransaction tct (payDate, 8.0, empId);
	tct.Execute();
	PaydayTransaction pt (payDate);
	pt.Execute();
	shared_ptr<Paycheck> pc = pt.GetPaycheck(empId);
	REQUIRE(pc != nullptr);
	REQUIRE(payDate == pc->PayPeriodEndDate());
	REQUIRE(8*15.24f == pc->GetGrossPay());
	REQUIRE("Hold" ==  pc->GetField("Disposition"));
	REQUIRE((9.42f + 19.42f) == pc->GetDeductions());
	REQUIRE((float)((8*15.24f)-(9.42f + 19.42f)) == pc->GetNetPay());
}

TEST_CASE("Service charges spanning multiple pay periods",
		"[service-charges-spanning-multiple-pay-periods]")
{
	int empId = 36;
	AddHourlyEmployee t (	empId, "Bill", "Home", 15.24);
	t.Execute();
	int memberId = 7734;
	ChangeMemberTransaction cmt (empId, memberId, 9.42);
	cmt.Execute();
	Date payDate ("09/11/2001");//Friday
	Date earlyDate ("02/11/2001"); // previous Friday
	Date lateDate ("16/11/2001"); // next Friday
	ServiceChargeTransaction sct (memberId, payDate, 19.42);
	sct.Execute();
	ServiceChargeTransaction sctEarly (memberId,earlyDate,100.00);
	sctEarly.Execute();
	ServiceChargeTransaction sctLate (memberId,lateDate,200.00);
	sctLate.Execute();
	TimeCardTransaction tct (payDate, 8.0, empId);
	tct.Execute();
	PaydayTransaction pt (payDate);
	pt.Execute();
	shared_ptr<Paycheck> pc = pt.GetPaycheck(empId);
	REQUIRE(pc != nullptr);
	REQUIRE(payDate == pc->PayPeriodEndDate());
	REQUIRE(8*15.24f == pc->GetGrossPay());
	REQUIRE("Hold" == pc->GetField("Disposition"));
	REQUIRE((9.42f + 19.42f) == pc->GetDeductions());
	REQUIRE((float)((8*15.24) - (9.42 + 19.42)) == pc->GetNetPay());
}

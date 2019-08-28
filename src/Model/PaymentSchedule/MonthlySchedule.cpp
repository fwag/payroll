/*
 * MonthlySchedule.cpp
 *
 *  Created on: Aug 28, 2019
 *      Author: tbmnxvmuser
 */

#include "MonthlySchedule.h"

namespace Payroll {

int MonthlySchedule::GetLastMonthDay (int month, int year)
{
   if(month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month == 11)
       return 31;
   else if(month == 3 || month == 5 || month == 8 || month == 10)
       return 30;
   else {
       if(year % 4 == 0) {
           if(year % 100 == 0) {
               if(year % 400 == 0)
                   return 29;
               return 28;
           }
           return 29;
       }
       return 28;
   }
}

bool MonthlySchedule::IsPayday(time_t date)
{
	bool res = false;
	int lastMonthDay;
	tm *ltm = localtime(&date);

	lastMonthDay = GetLastMonthDay (ltm->tm_mon, ltm->tm_year+1900);

	if (ltm->tm_mday == lastMonthDay)
	{
		res = true;
	}

	return res;
}

} /* namespace Payroll */

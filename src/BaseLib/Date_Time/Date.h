#pragma once

#include <iostream>

using namespace std;

namespace BaseLib
{
    class Date
    {
    private:
        short _Day = 1;
        short _Month = 1;
        short _Year = 1900;

    public:
        enum enDateCompare { Before = -1, Equal = 0, After = 1 };

        // Constructors
        Date();
        Date(string sDate);
        Date(short Day, short Month, short Year);
        Date(short DateOrderInYear, short Year);

        static Date GetCurrnetDate();

        // Standard Accessors (Getters/Setters)
        void SetDay(short Day);
        short GetDay() const;

        void SetMonth(short Month);
        short GetMonth() const;

        void SetYear(short Year);
        short GetYear() const;

        void SetHours(short Hours);
        short GetHours() const;

        void SetMinutes(short Minutes);
        short GetMinutes() const;

        void SetSeconds(short Seconds);
        short GetSeconds() const;

        // Methods
        void Print();
        static Date GetSystemDate();
        static bool IsValidDate(Date Date);
        bool IsValid();
        static string DateToString(Date Date);
        string DateToString();

        static bool isLeapYear(short Year);
        bool isLeapYear() const;

        static short NumberOfDaysInAYear(short Year);
        short NumberOfDaysInAYear() const;

        static short NumberOfHoursInAYear(short Year);
        short NumberOfHoursInAYear() const;

        static int NumberOfMinutesInAYear(short Year);
        int NumberOfMinutesInAYear() const;

        static int NumberOfSecondsInAYear(short Year);
        int NumberOfSecondsInAYear() const;

        static short NumberOfDaysInAMonth(short Month, short Year);
        short NumberOfDaysInAMonth() const;

        static short NumberOfHoursInAMonth(short Month, short Year);
        short NumberOfHoursInAMonth() const;

        static int NumberOfMinutesInAMonth(short Month, short Year);
        int NumberOfMinutesInAMonth() const;

        static int NumberOfSecondsInAMonth(short Month, short Year);
        int NumberOfSecondsInAMonth() const;

        static short DayOfWeekOrder(short Day, short Month, short Year);
        short DayOfWeekOrder() const;

        static string DayShortName(short DayOfWeekOrder);
        static string DayShortName(short Day, short Month, short Year);
        string DayShortName() const;

        static string MonthShortName(short MonthNumber);
        string MonthShortName() const;

        static void PrintMonthCalendar(short Month, short Year);
        void PrintMonthCalendar();

        static void PrintYearCalendar(int Year);
        void PrintYearCalendar();

        static short DaysFromTheBeginingOfTheYear(short Day, short Month, short Year);
        short DaysFromTheBeginingOfTheYear() const;

        static Date GetDateFromDayOrderInYear(short DateOrderInYear, short Year);

        static bool IsDate1BeforeDate2(Date Date1, Date Date2);
        bool IsDateBeforeDate2(Date Date2) const;

        static bool IsDate1EqualDate2(Date Date1, Date Date2);
        bool IsDateEqualDate2(Date Date2) const;

        static bool IsLastDayInMonth(Date Date);
        bool IsLastDayInMonth() const;

        static bool IsLastMonthInYear(short Month);

        static Date AddOneDay(Date Date);
        void AddOneDay();

        static void SwapDates(Date& Date1, Date& Date2);

        static int GetDifferenceInDays(Date Date1, Date Date2, bool IncludeEndDay = false);
        int GetDifferenceInDays(Date Date2, bool IncludeEndDay = false) const;

        static short CalculateMyAgeInDays(Date DateOfBirth);

        static Date IncreaseDateByOneWeek(Date& Date);
        void IncreaseDateByOneWeek();

        static Date IncreaseDateByXWeeks(short Weeks, Date& Date);
        void IncreaseDateByXWeeks(short Weeks);

        static Date IncreaseDateByOneMonth(Date& Date);
        void IncreaseDateByOneMonth();

        static Date IncreaseDateByXDays(short Days, Date& Date);
        void IncreaseDateByXDays(short Days);

        static Date IncreaseDateByXMonths(short Months, Date& Date);
        void IncreaseDateByXMonths(short Months);

        static Date IncreaseDateByOneYear(Date& Date);
        void IncreaseDateByOneYear();

        static Date IncreaseDateByXYears(short Years, Date& Date);
        void IncreaseDateByXYears(short Years);

        static Date IncreaseDateByOneDecade(Date& Date);
        void IncreaseDateByOneDecade();

        static Date IncreaseDateByXDecades(short Decade, Date& Date);
        void IncreaseDateByXDecades(short Decade);

        static Date IncreaseDateByOneCentury(Date& Date);
        void IncreaseDateByOneCentury();

        static Date IncreaseDateByOneMillennium(Date& Date);
        void IncreaseDateByOneMillennium();

        static Date DecreaseDateByOneDay(Date Date);
        void DecreaseDateByOneDay();

        static Date DecreaseDateByOneWeek(Date& Date);
        void DecreaseDateByOneWeek();

        static Date DecreaseDateByXWeeks(short Weeks, Date& Date);
        void DecreaseDateByXWeeks(short Weeks);

        static Date DecreaseDateByOneMonth(Date& Date);
        void DecreaseDateByOneMonth();

        static Date DecreaseDateByXDays(short Days, Date& Date);
        void DecreaseDateByXDays(short Days);

        static Date DecreaseDateByXMonths(short Months, Date& Date);
        void DecreaseDateByXMonths(short Months);

        static Date DecreaseDateByOneYear(Date& Date);
        void DecreaseDateByOneYear();

        static Date DecreaseDateByXYears(short Years, Date& Date);
        void DecreaseDateByXYears(short Years);

        static Date DecreaseDateByOneDecade(Date& Date);
        void DecreaseDateByOneDecade();

        static Date DecreaseDateByXDecades(short Decades, Date& Date);
        void DecreaseDateByXDecades(short Decades);

        static Date DecreaseDateByOneCentury(Date& Date);
        void DecreaseDateByOneCentury();

        static Date DecreaseDateByOneMillennium(Date& Date);
        void DecreaseDateByOneMillennium();

        static short IsEndOfWeek(Date Date);
        short IsEndOfWeek() const;

        static bool IsWeekEnd(Date Date);
        bool IsWeekEnd() const;

        static bool IsBusinessDay(Date Date);
        bool IsBusinessDay() const;

        static short DaysUntilTheEndOfWeek(Date Date);
        short DaysUntilTheEndOfWeek() const;

        static short DaysUntilTheEndOfMonth(Date Date1);
        short DaysUntilTheEndOfMonth() const;

        static short DaysUntilTheEndOfYear(Date Date1);
        short DaysUntilTheEndOfYear() const;

        static short CalculateBusinessDays(Date DateFrom, Date DateTo);
        static short CalculateVacationDays(Date DateFrom, Date DateTo);
        static Date CalculateVacationReturnDate(Date DateFrom, short VacationDays);

        static bool IsDate1AfterDate2(Date Date1, Date Date2);
        bool IsDateAfterDate2(Date Date2) const;

        static enDateCompare CompareDates(Date Date1, Date Date2);
        enDateCompare CompareDates(Date Date2) const;
    };

} // namespace BaseLib
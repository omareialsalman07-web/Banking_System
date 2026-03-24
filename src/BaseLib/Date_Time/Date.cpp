#include "Date.h"

namespace BaseLib
{

Date::Date() {
    time_t t = time(0);
    struct tm now;
	localtime_s(&now, &t); // if linux use localtime_r instead of localtime_s
    _Day = now.tm_mday;
    _Month = now.tm_mon + 1;
    _Year = now.tm_year + 1900;
}

Date::Date(string sDate) {
    vector <string> vDate = String::Split(sDate, "/");
    if(vDate.size() >= 3) {
        _Day = stoi(vDate[0]);
        _Month = stoi(vDate[1]);
        _Year = stoi(vDate[2]);
    }
}

Date::Date(short Day, short Month, short Year) {
    _Day = Day;
    _Month = Month;
    _Year = Year;
}

Date::Date(short DateOrderInYear, short Year) {
    Date Date1 = GetDateFromDayOrderInYear(DateOrderInYear, Year);
    _Day = Date1.GetDay();
    _Month = Date1.GetMonth();
    _Year = Date1.GetYear();
}

void Date::SetDay(short Day) { _Day = Day; }
short Date::GetDay() const { return _Day; }

void Date::SetMonth(short Month) { _Month = Month; }
short Date::GetMonth() const { return _Month; }

void Date::SetYear(short Year) { _Year = Year; }
short Date::GetYear() const { return _Year; }

void Date::Print() { cout << DateToString() << endl; }

Date Date::GetSystemDate() {
    time_t t = time(0);
    struct tm now;
    localtime_s(&now, &t);
    return Date(now.tm_mday, now.tm_mon + 1, now.tm_year + 1900);
}

bool Date::IsValidDate(Date Date) {
    if (Date.GetMonth() < 1 || Date.GetMonth() > 12) return false;
    short DaysInMonth = NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear());
    return (Date.GetDay() >= 1 && Date.GetDay() <= DaysInMonth);
}

bool Date::IsValid() { return IsValidDate(*this); }

string Date::DateToString(Date Date) {
    return to_string(Date.GetDay()) + "/" + to_string(Date.GetMonth()) + "/" + to_string(Date.GetYear());
}

string Date::DateToString() { return DateToString(*this); }

bool Date::isLeapYear(short Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

bool Date::isLeapYear() const { return isLeapYear(_Year); }

short Date::NumberOfDaysInAYear(short Year) { return isLeapYear(Year) ? 366 : 365; }
short Date::NumberOfDaysInAYear() const { return NumberOfDaysInAYear(_Year); }

short Date::NumberOfHoursInAYear(short Year) { return NumberOfDaysInAYear(Year) * 24; }
short Date::NumberOfHoursInAYear() const { return NumberOfHoursInAYear(_Year); }

int Date::NumberOfMinutesInAYear(short Year) { return NumberOfHoursInAYear(Year) * 60; }
int Date::NumberOfMinutesInAYear() const { return NumberOfMinutesInAYear(_Year); }

int Date::NumberOfSecondsInAYear(short Year) { return NumberOfMinutesInAYear(Year) * 60; }
int Date::NumberOfSecondsInAYear() const { return NumberOfSecondsInAYear(_Year); }

short Date::NumberOfDaysInAMonth(short Month, short Year) {
    if (Month < 1 || Month > 12) return 0;
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

short Date::NumberOfDaysInAMonth() const { return NumberOfDaysInAMonth(_Month, _Year); }

short Date::NumberOfHoursInAMonth(short Month, short Year) { return NumberOfDaysInAMonth(Month, Year) * 24; }
short Date::NumberOfHoursInAMonth() const { return NumberOfHoursInAMonth(_Month, _Year); }

int Date::NumberOfMinutesInAMonth(short Month, short Year) { return NumberOfHoursInAMonth(Month, Year) * 60; }
int Date::NumberOfMinutesInAMonth() const { return NumberOfMinutesInAMonth(_Month, _Year); }

int Date::NumberOfSecondsInAMonth(short Month, short Year) { return NumberOfMinutesInAMonth(Month, Year) * 60; }
int Date::NumberOfSecondsInAMonth() const { return NumberOfSecondsInAMonth(_Month, _Year); }

short Date::DayOfWeekOrder(short Day, short Month, short Year) {
    short a = (14 - Month) / 12;
    short y = Year - a;
    short m = Month + (12 * a) - 2;
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short Date::DayOfWeekOrder() const { return DayOfWeekOrder(_Day, _Month, _Year); }

string Date::DayShortName(short DayOfWeekOrder) {
    string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return arrDayNames[DayOfWeekOrder];
}

string Date::DayShortName(short Day, short Month, short Year) {
    return DayShortName(DayOfWeekOrder(Day, Month, Year));
}

string Date::DayShortName() const { return DayShortName(DayOfWeekOrder(_Day, _Month, _Year)); }

string Date::MonthShortName(short MonthNumber) {
    string Months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    return Months[MonthNumber - 1];
}

string Date::MonthShortName() const { return MonthShortName(_Month); }

void Date::PrintMonthCalendar(short Month, short Year) {
    int current = DayOfWeekOrder(1, Month, Year);
    int NumberOfDays = NumberOfDaysInAMonth(Month, Year);
    printf("\n  _______________%s_______________\n\n", MonthShortName(Month).c_str());
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
    int i;
    for (i = 0; i < current; i++) printf("     ");
    for (int j = 1; j <= NumberOfDays; j++) {
        printf("%5d", j);
        if (++i == 7) { i = 0; printf("\n"); }
    }
    printf("\n  _________________________________\n");
}

void Date::PrintMonthCalendar() { PrintMonthCalendar(_Month, _Year); }

void Date::PrintYearCalendar(int Year) {
    printf("\n  _________________________________\n\n");
    printf("           Calendar - %d\n", Year);
    printf("  _________________________________\n");
    for (int i = 1; i <= 12; i++) PrintMonthCalendar(i, Year);
}

void Date::PrintYearCalendar() { PrintYearCalendar(_Year); }

short Date::DaysFromTheBeginingOfTheYear(short Day, short Month, short Year) {
    short TotalDays = 0;
    for (int i = 1; i <= Month - 1; i++) TotalDays += NumberOfDaysInAMonth(i, Year);
    TotalDays += Day;
    return TotalDays;
}

short Date::DaysFromTheBeginingOfTheYear() const { return DaysFromTheBeginingOfTheYear(_Day, _Month, _Year); }

Date Date::GetDateFromDayOrderInYear(short DateOrderInYear, short Year) {
    Date Date;
    short RemainingDays = DateOrderInYear;
    Date.SetYear(Year);
    Date.SetMonth(1);
    while (true) {
        short MonthDays = NumberOfDaysInAMonth(Date.GetMonth(), Year);
        if (RemainingDays > MonthDays) {
            RemainingDays -= MonthDays;
            Date.SetMonth(Date.GetMonth() + 1);
        } else {
            Date.SetDay(RemainingDays);
            break;
        }
    }
    return Date;
}

void Date::AddDays(short Days) {
    short RemainingDays = Days + DaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
    _Month = 1;
    while (true) {
        short MonthDays = NumberOfDaysInAMonth(_Month, _Year);
        if (RemainingDays > MonthDays) {
            RemainingDays -= MonthDays;
            _Month++;
            if (_Month > 12) { _Month = 1; _Year++; }
        } else {
            _Day = RemainingDays;
            break;
        }
    }
}

bool Date::IsDate1BeforeDate2(Date Date1, Date Date2) {
    if (Date1.GetYear() < Date2.GetYear()) return true;
    if (Date1.GetYear() > Date2.GetYear()) return false;
    if (Date1.GetMonth() < Date2.GetMonth()) return true;
    if (Date1.GetMonth() > Date2.GetMonth()) return false;
    return Date1.GetDay() < Date2.GetDay();
}

bool Date::IsDateBeforeDate2(Date Date2) const { return IsDate1BeforeDate2(*this, Date2); }

bool Date::IsDate1EqualDate2(Date Date1, Date Date2) {
    return (Date1.GetYear() == Date2.GetYear() && Date1.GetMonth() == Date2.GetMonth() && Date1.GetDay() == Date2.GetDay());
}

bool Date::IsDateEqualDate2(Date Date2) const { return IsDate1EqualDate2(*this, Date2); }

bool Date::IsLastDayInMonth(Date Date) { return (Date.GetDay() == NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear())); }
bool Date::IsLastDayInMonth() const { return IsLastDayInMonth(*this); }

bool Date::IsLastMonthInYear(short Month) { return (Month == 12); }

Date Date::AddOneDay(Date Date) {
    if (IsLastDayInMonth(Date)) {
        if (IsLastMonthInYear(Date.GetMonth())) {
            Date.SetMonth(1); Date.SetDay(1); Date.SetYear(Date.GetYear() + 1);
        } else {
            Date.SetDay(1); Date.SetMonth(Date.GetMonth() + 1);
        }
    } else {
        Date.SetDay(Date.GetDay() + 1);
    }
    return Date;
}

void Date::AddOneDay() { *this = AddOneDay(*this); }

void Date::SwapDates(Date& Date1, Date& Date2) {
    Date TempDate = Date1;
    Date1 = Date2;
    Date2 = TempDate;
}

int Date::GetDifferenceInDays(Date Date1, Date Date2, bool IncludeEndDay) {
    int Days = 0;
    short SwapFlagValue = 1;
    if (!IsDate1BeforeDate2(Date1, Date2)) {
        SwapDates(Date1, Date2);
        SwapFlagValue = -1;
    }
    while (IsDate1BeforeDate2(Date1, Date2)) {
        Days++;
        Date1 = AddOneDay(Date1);
    }
    return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
}

int Date::GetDifferenceInDays(Date Date2, bool IncludeEndDay) const { return GetDifferenceInDays(*this, Date2, IncludeEndDay); }

short Date::CalculateMyAgeInDays(Date DateOfBirth) { return GetDifferenceInDays(DateOfBirth, Date::GetSystemDate(), true); }

Date Date::IncreaseDateByOneWeek(Date& Date) {
    for (int i = 1; i <= 7; i++) Date = AddOneDay(Date);
    return Date;
}

void Date::IncreaseDateByOneWeek() { IncreaseDateByOneWeek(*this); }

Date Date::IncreaseDateByXWeeks(short Weeks, Date& Date) {
    for (short i = 1; i <= Weeks; i++) IncreaseDateByOneWeek(Date);
    return Date;
}

void Date::IncreaseDateByXWeeks(short Weeks) { IncreaseDateByXWeeks(Weeks, *this); }

Date Date::IncreaseDateByOneMonth(Date& Date) {
    if (Date.GetMonth() == 12) { Date.SetMonth(1); Date.SetYear(Date.GetYear() + 1); }
    else Date.SetMonth(Date.GetMonth() + 1);
    short DaysInMonth = NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear());
    if (Date.GetDay() > DaysInMonth) Date.SetDay(DaysInMonth);
    return Date;
}

void Date::IncreaseDateByOneMonth() { IncreaseDateByOneMonth(*this); }

Date Date::IncreaseDateByXDays(short Days, Date& Date) {
    for (short i = 1; i <= Days; i++) Date = AddOneDay(Date);
    return Date;
}

void Date::IncreaseDateByXDays(short Days) { IncreaseDateByXDays(Days, *this); }

Date Date::IncreaseDateByXMonths(short Months, Date& Date) {
    for (short i = 1; i <= Months; i++) IncreaseDateByOneMonth(Date);
    return Date;
}

void Date::IncreaseDateByXMonths(short Months) { IncreaseDateByXMonths(Months, *this); }

Date Date::IncreaseDateByOneYear(Date& Date) { Date.SetYear(Date.GetYear() + 1); return Date; }
void Date::IncreaseDateByOneYear() { IncreaseDateByOneYear(*this); }

Date Date::IncreaseDateByXYears(short Years, Date& Date) { Date.SetYear(Date.GetYear() + Years); return Date; }
void Date::IncreaseDateByXYears(short Years) { IncreaseDateByXYears(Years, *this); }

Date Date::IncreaseDateByOneDecade(Date& Date) { Date.SetYear(Date.GetYear() + 10); return Date; }
void Date::IncreaseDateByOneDecade() { IncreaseDateByOneDecade(*this); }

Date Date::IncreaseDateByXDecades(short Decade, Date& Date) { Date.SetYear(Date.GetYear() + Decade * 10); return Date; }
void Date::IncreaseDateByXDecades(short Decade) { IncreaseDateByXDecades(Decade, *this); }

Date Date::IncreaseDateByOneCentury(Date& Date) { Date.SetYear(Date.GetYear() + 100); return Date; }
void Date::IncreaseDateByOneCentury() { IncreaseDateByOneCentury(*this); }

Date Date::IncreaseDateByOneMillennium(Date& Date) { Date.SetYear(Date.GetYear() + 1000); return Date; }
void Date::IncreaseDateByOneMillennium() { IncreaseDateByOneMillennium(*this); }

Date Date::DecreaseDateByOneDay(Date Date) {
    if (Date.GetDay() == 1) {
        if (Date.GetMonth() == 1) { Date.SetMonth(12); Date.SetDay(31); Date.SetYear(Date.GetYear() - 1); }
        else { Date.SetMonth(Date.GetMonth() - 1); Date.SetDay(NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear())); }
    } else Date.SetDay(Date.GetDay() - 1);
    return Date;
}

void Date::DecreaseDateByOneDay() { *this = DecreaseDateByOneDay(*this); }

Date Date::DecreaseDateByOneWeek(Date& Date) {
    for (int i = 1; i <= 7; i++) Date = DecreaseDateByOneDay(Date);
    return Date;
}

void Date::DecreaseDateByOneWeek() { DecreaseDateByOneWeek(*this); }

Date Date::DecreaseDateByXWeeks(short Weeks, Date& Date) {
    for (short i = 1; i <= Weeks; i++) DecreaseDateByOneWeek(Date);
    return Date;
}

void Date::DecreaseDateByXWeeks(short Weeks) { DecreaseDateByXWeeks(Weeks, *this); }

Date Date::DecreaseDateByOneMonth(Date& Date) {
    if (Date.GetMonth() == 1) { Date.SetMonth(12); Date.SetYear(Date.GetYear() - 1); }
    else Date.SetMonth(Date.GetMonth() - 1);
    short DaysInMonth = NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear());
    if (Date.GetDay() > DaysInMonth) Date.SetDay(DaysInMonth);
    return Date;
}

void Date::DecreaseDateByOneMonth() { DecreaseDateByOneMonth(*this); }

Date Date::DecreaseDateByXDays(short Days, Date& Date) {
    for (short i = 1; i <= Days; i++) Date = DecreaseDateByOneDay(Date);
    return Date;
}

void Date::DecreaseDateByXDays(short Days) { DecreaseDateByXDays(Days, *this); }

Date Date::DecreaseDateByXMonths(short Months, Date& Date) {
    for (short i = 1; i <= Months; i++) DecreaseDateByOneMonth(Date);
    return Date;
}

void Date::DecreaseDateByXMonths(short Months) { DecreaseDateByXMonths(Months, *this); }

Date Date::DecreaseDateByOneYear(Date& Date) { Date.SetYear(Date.GetYear() - 1); return Date; }
void Date::DecreaseDateByOneYear() { DecreaseDateByOneYear(*this); }

Date Date::DecreaseDateByXYears(short Years, Date& Date) { Date.SetYear(Date.GetYear() - Years); return Date; }
void Date::DecreaseDateByXYears(short Years) { DecreaseDateByXYears(Years, *this); }

Date Date::DecreaseDateByOneDecade(Date& Date) { Date.SetYear(Date.GetYear() - 10); return Date; }
void Date::DecreaseDateByOneDecade() { DecreaseDateByOneDecade(*this); }

Date Date::DecreaseDateByXDecades(short Decades, Date& Date) { Date.SetYear(Date.GetYear() - Decades * 10); return Date; }
void Date::DecreaseDateByXDecades(short Decades) { DecreaseDateByXDecades(Decades, *this); }

Date Date::DecreaseDateByOneCentury(Date& Date) { Date.SetYear(Date.GetYear() - 100); return Date; }
void Date::DecreaseDateByOneCentury() { DecreaseDateByOneCentury(*this); }

Date Date::DecreaseDateByOneMillennium(Date& Date) { Date.SetYear(Date.GetYear() - 1000); return Date; }
void Date::DecreaseDateByOneMillennium() { DecreaseDateByOneMillennium(*this); }

short Date::IsEndOfWeek(Date Date) { return DayOfWeekOrder(Date.GetDay(), Date.GetMonth(), Date.GetYear()) == 6; }
short Date::IsEndOfWeek() const { return IsEndOfWeek(*this); }

bool Date::IsWeekEnd(Date Date) {
    short DayIndex = DayOfWeekOrder(Date.GetDay(), Date.GetMonth(), Date.GetYear());
    return (DayIndex == 5 || DayIndex == 6);
}

bool Date::IsWeekEnd() const { return IsWeekEnd(*this); }
bool Date::IsBusinessDay(Date Date) { return !IsWeekEnd(Date); }
bool Date::IsBusinessDay() const { return IsBusinessDay(*this); }

short Date::DaysUntilTheEndOfWeek(Date Date) { return 6 - DayOfWeekOrder(Date.GetDay(), Date.GetMonth(), Date.GetYear()); }
short Date::DaysUntilTheEndOfWeek() const { return DaysUntilTheEndOfWeek(*this); }

short Date::DaysUntilTheEndOfMonth(Date Date1) {
    Date EndOfMonth(NumberOfDaysInAMonth(Date1.GetMonth(), Date1.GetYear()), Date1.GetMonth(), Date1.GetYear());
    return GetDifferenceInDays(Date1, EndOfMonth, true);
}

short Date::DaysUntilTheEndOfMonth() const { return DaysUntilTheEndOfMonth(*this); }

short Date::DaysUntilTheEndOfYear(Date Date1) {
    Date EndOfYear(31, 12, Date1.GetYear());
    return GetDifferenceInDays(Date1, EndOfYear, true);
}

short Date::DaysUntilTheEndOfYear() const { return DaysUntilTheEndOfYear(*this); }

short Date::CalculateBusinessDays(Date DateFrom, Date DateTo) {
    short Days = 0;
    while (IsDate1BeforeDate2(DateFrom, DateTo)) {
        if (IsBusinessDay(DateFrom)) Days++;
        DateFrom = AddOneDay(DateFrom);
    }
    return Days;
}

short Date::CalculateVacationDays(Date DateFrom, Date DateTo) { return CalculateBusinessDays(DateFrom, DateTo); }

Date Date::CalculateVacationReturnDate(Date DateFrom, short VacationDays) {
    short WeekEndCounter = 0;
    for (short i = 1; i <= VacationDays; i++) {
        if (IsWeekEnd(DateFrom)) WeekEndCounter++;
        DateFrom = AddOneDay(DateFrom);
    }
    for (short i = 1; i <= WeekEndCounter; i++) DateFrom = AddOneDay(DateFrom);
    return DateFrom;
}

bool Date::IsDate1AfterDate2(Date Date1, Date Date2) { return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2)); }
bool Date::IsDateAfterDate2(Date Date2) const { return IsDate1AfterDate2(*this, Date2); }

Date::enDateCompare Date::CompareDates(Date Date1, Date Date2) {
    if (IsDate1BeforeDate2(Date1, Date2)) return enDateCompare::Before;
    if (IsDate1EqualDate2(Date1, Date2)) return enDateCompare::Equal;
    return enDateCompare::After;
}

Date::enDateCompare Date::CompareDates(Date Date2) const { return CompareDates(*this, Date2); }

} // namespace BaseLib
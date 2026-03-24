#include "Period.h"

namespace BaseLib
{

Period::Period(Date StartDate, Date DateTo)
{
    this->StartDate = StartDate;
    this->EndDate = DateTo; // Fixed: was using 'EndDate' parameter which didn't exist
}

bool Period::IsOverlapPeriods(Period Period1, Period Period2)
{
    // If Period 2 ends before Period 1 starts OR Period 2 starts after Period 1 ends, 
    // there is no overlap.
    if (
        Date::CompareDates(Period2.EndDate, Period1.StartDate) == Date::enDateCompare::Before
        ||
        Date::CompareDates(Period2.StartDate, Period1.EndDate) == Date::enDateCompare::After
        )
        return false;
    else
        return true;
}

bool Period::IsOverLapWith(Period Period2)
{
    return IsOverlapPeriods(*this, Period2);
}

void Period::Print()
{
    std::cout << "Period Start: ";
    StartDate.Print();

    std::cout << "Period End: ";
    EndDate.Print();
}

} // namespace BaseLib
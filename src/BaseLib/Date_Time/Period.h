#pragma once
#include "Date.h"

namespace BaseLib
{

class Period
{
public:
    Date StartDate;
    Date EndDate;

    Period(Date StartDate, Date DateTo);

    static bool IsOverlapPeriods(Period Period1, Period Period2);

    bool IsOverLapWith(Period Period2);

    void Print();
};

} // namespace BaseLib
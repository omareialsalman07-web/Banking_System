#include "Time.h"

#include <string>
#include <ctime>

BaseLib::Time::Time()
{
    time_t t = time(0);
    struct tm now;
    localtime_s(&now, &t);

    _Hours = now.tm_hour;
    _Minutes = now.tm_min;
    _Seconds = now.tm_sec;
}

BaseLib::Time::Time(short Hours, short Minutes, short Seconds)
{
    _Hours = Hours;
    _Minutes = Minutes;
    _Seconds = Seconds;
}

BaseLib::Time BaseLib::Time::GetCurrentTime()
{
    return Time();
}

std::string BaseLib::Time::TimeToString() const
{
    return std::to_string(_Hours) + ":" +
        std::to_string(_Minutes) + ":" +
        std::to_string(_Seconds);
}

// ================= Hours =================

void BaseLib::Time::AddOneHour(Time& time)
{
    if (time.GetHours() >= 23)
        time.SetHours(0);
    else
        time.SetHours(time.GetHours() + 1);
}

void BaseLib::Time::AddOneHour()
{
    AddOneHour(*this);
}

void BaseLib::Time::AddHours(short Hours, Time& time)
{
    for (int i = 0; i < Hours; i++)
        AddOneHour(time);
}

void BaseLib::Time::AddHours(short Hours)
{
    AddHours(Hours, *this);
}

// ================= Minutes =================

void BaseLib::Time::AddOneMinute(Time& time)
{
    if (time.GetMinutes() >= 59)
    {
        time.SetMinutes(0);
        AddOneHour(time);
    }
    else
    {
        time.SetMinutes(time.GetMinutes() + 1);
    }
}

void BaseLib::Time::AddOneMinute()
{
    AddOneMinute(*this);
}

void BaseLib::Time::AddMinutes(Time& time, short minutes)
{
    for (int i = 0; i < minutes; i++)
        AddOneMinute(time);
}

void BaseLib::Time::AddMinutes(short Minutes)
{
    AddMinutes(*this, Minutes);
}

// ================= Seconds =================

void BaseLib::Time::AddOneSecond(Time& time)
{
    if (time.GetSeconds() >= 59)
    {
        time.SetSeconds(0);
        AddOneMinute(time);
    }
    else
    {
        time.SetSeconds(time.GetSeconds() + 1);
    }
}

void BaseLib::Time::AddOneSecond()
{
    AddOneSecond(*this);
}

void BaseLib::Time::AddSeconds(Time& time, short Seconds)
{
    for (int i = 0; i < Seconds; i++)
        AddOneSecond(time);
}

void BaseLib::Time::AddSeconds(short Seconds)
{
    AddSeconds(*this, Seconds);
}
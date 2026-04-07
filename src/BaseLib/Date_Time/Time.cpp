#include "Time.h"

#include <string>
#include <vector>
#include <ctime>
#include "../String.h"

BaseLib::Time::Time()
{
    time_t t = time(0);
    struct tm now;
    localtime_s(&now, &t); // if linux use localtime_r instead of localtime_s

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
	return std::to_string(_Hours) + ":" + std::to_string(_Minutes) + ":" + std::to_string(_Seconds);
}

void BaseLib::Time::AddOneHour(Time& time)
{
	if (time.GetHours() >= 24)
	{
		time.SetHours(1);

	}
	else
	{
		time.SetHours(time.GetHours() + 1);
	}
}

void BaseLib::Time::AddOneHour()
{
	AddOneHour(*this);
}

void BaseLib::Time::AddHours(short Hours, Time& time)
{
	for (int i = 0; i < Hours; i++)
	{
		AddOneHour(time);
	}
}

void BaseLib::Time::AddHours(short Hours)
{
	AddHours(Hours, *this);
}

void BaseLib::Time::AddOneMinute(Time& time)
{
	if (time.GetMinutes() >= 60)
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
	{
		AddOneMinute(time);
	}
}

void BaseLib::Time::AddMinutes(short Minutes)
{
	AddMinutes(*this, Minutes);
}

void BaseLib::Time::AddOneSecond(Time& time)
{
	if (time.GetSeconds() >= 60)
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
	AddOneHour(*this);
}

void BaseLib::Time::AddSeconds(Time& time, short Seconds)
{
	for (int i = 0; i < Seconds; i++)
	{
		AddOneSecond(time);
	}
}

void BaseLib::Time::AddSeconds(short Seconds)
{
	AddSeconds(*this, Seconds);
}

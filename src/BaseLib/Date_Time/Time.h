#pragma once
#include <iostream>

namespace BaseLib
{
	class Time
	{
	private:
		short _Hours = 1;
		short _Minutes = 0;
		short _Seconds = 0;
	public:
		Time();
		Time(short Hours, short Minutes, short Seconds);
		static Time GetCurrentTime();

		void SetHours(short Hours) { _Hours = Hours; }
		short GetHours() const { return _Hours; }

		void SetMinutes(short Minutes) { _Minutes = Minutes; }
		short GetMinutes() const { return _Minutes; }

		void SetSeconds(short Seconds) { _Seconds = Seconds; }
		short GetSeconds() const { return _Seconds; }

		static void AddOneHour(Time& time);
		void AddOneHour();
		static void AddHours(short Hours, Time& time);
		void AddHours(short Hours);

		static void AddOneMinute(Time& time);
		void AddOneMinute();
		static void AddMinutes(Time& time, short minutes);
		void AddMinutes(short Minutes);

		static void AddOneSecond(Time& time);
		void AddOneSecond();
		static void AddSeconds(Time& time, short Seconds);
		void AddSeconds(short Seconds);

		std::string TimeToString() const;
	};
}
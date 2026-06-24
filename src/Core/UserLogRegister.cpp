#include "UserLogRegister.h"

#include "BankUser.h"

#include <BaseLib/Date_Time/Date.h>
#include <BaseLib/Date_Time/Time.h>
#include <BaseLib/String.h>

#include <vector>


UserLogRegister::UserLogRegister(const std::string& userName)
{
    m_UserName = userName;

    m_DateTime =
        BaseLib::Date::GetCurrnetDate().ToString()
        + " - " +
        BaseLib::Time::GetCurrentTime().ToString();
}


std::string UserLogRegister::ToLine(const std::string& separator) const
{
    return
        m_DateTime + separator +
        m_UserName;
}


void UserLogRegister::FromLine(std::string line, const std::string& separator)
{
    std::vector<std::string> data =
        BaseLib::String::Split(line, separator);


    if (data.size() < 2)
        return;


    m_DateTime = data[0];

    m_UserName = data[1];
}
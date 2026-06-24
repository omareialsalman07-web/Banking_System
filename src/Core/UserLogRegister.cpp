#include "UserLogRegister.h"

#include <BaseLib/Date_Time/Date.h>
#include <BaseLib/Date_Time/Time.h>
#include <BaseLib/String.h>
#include "Repository.h"
#include <string>

UserLogRegister::UserLogRegister(const BankUser& User) : _User(User)
{
}

std::string UserLogRegister::ToLine(const std::string& separetor) const
{
    std::string line = BaseLib::Date::GetCurrnetDate().DateToString() + " - " + BaseLib::Time::GetCurrentTime().TimeToString();
    line = line + separetor + _User.GetUserName();
    return line;
}

void UserLogRegister::FromLine(std::string Line, const std::string& separetor)
{
    std::vector<std::string> vData = BaseLib::String::Split(Line, separetor);

    SetDateTime(vData[0]);

    Repository<BankUser> userRepo(Repository<BankUser>::GetStandard_UsersFileName());
    _User = userRepo.Find(vData[1]);
}
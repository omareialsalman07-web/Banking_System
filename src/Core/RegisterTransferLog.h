#pragma once

#include "IPersistable.h"
#include <BaseLib/String.h>
#include <BaseLib/Date_Time/Date.h>
#include <BaseLib/Date_Time/Time.h>


class RegisterTransferLog : public IPersistable
{
private:
    std::string m_DateTime;
    std::string m_FromAccount;
    std::string m_ToAccount;
    std::string m_UserName;

    double m_Amount = 0;

public:
    RegisterTransferLog() = default;
    RegisterTransferLog(const BaseLib::Date& date, const BaseLib::Time& time, const std::string& fromAccount,
        const std::string& toAccount, double amount, const std::string& userName);

    std::string ToLine(const std::string& separator = "#//#") const override;
    void FromLine(std::string line, const std::string& separator = "#//#") override;
    inline std::string GetKey() const override;
    bool IsEmpty() const override;

    inline std::string GetFromAccount() const { return m_FromAccount; }
    inline std::string GetToAccount() const { return m_ToAccount; }
    inline std::string GetUserName() const{ return m_UserName; }
    inline double GetAmount() const { return m_Amount; }

    void SetDateTime(const BaseLib::Date& date, const BaseLib::Time& time);
    inline std::string GetDateTime() const { return m_DateTime; }
};
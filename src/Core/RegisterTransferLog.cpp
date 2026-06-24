#include "RegisterTransferLog.h"

#include "BankClient.h"
#include "BankUser.h"

#include <vector>


RegisterTransferLog::RegisterTransferLog(const BaseLib::Date& date, const BaseLib::Time& time,
    const std::string& fromAccount, const std::string& toAccount, double amount, const std::string& userName)
    :
    m_FromAccount(fromAccount),
    m_ToAccount(toAccount),
    m_UserName(userName),
    m_Amount(amount)
{
    SetDateTime(date, time);
}

std::string RegisterTransferLog::ToLine(const std::string& separator) const
{
    return
        m_DateTime + separator +
        m_FromAccount + separator +
        m_ToAccount + separator +
        std::to_string(m_Amount) + separator +
        m_UserName;
}

void RegisterTransferLog::FromLine(std::string line, const std::string& separator)
{
    std::vector<std::string> data = BaseLib::String::Split(line, separator);

    if (data.size() < 5)
        return;

    m_DateTime = data[0];
    m_FromAccount = data[1];
    m_ToAccount = data[2];
    m_Amount = std::stod(data[3]);
    m_UserName = data[4];
}


inline std::string RegisterTransferLog::GetKey() const
{
    return m_DateTime;
}


bool RegisterTransferLog::IsEmpty() const
{
    return
        m_FromAccount.empty() ||
        m_ToAccount.empty() ||
        m_UserName.empty();
}


void RegisterTransferLog::SetDateTime(const BaseLib::Date& date, const BaseLib::Time& time)
{
    m_DateTime = date.ToString() + " - " + time.ToString();
}
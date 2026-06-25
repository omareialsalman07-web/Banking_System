#include "BankClient.h"
#include <BaseLib/String.h>
#include "Repository.h"
#include "RegisterTransferLog.h"

#include <vector>

BankClient::BankClient(const std::string& FirstName, const std::string& LastName, const std::string& Email,
	const std::string& Phone, const std::string& AccountNumber, double Balance)
	: Person(FirstName, LastName, Email, Phone)
{
	_AccountNumber = AccountNumber;
	SetBalance(Balance);
}

std::string BankClient::ToLine(const std::string& separetor) const
{
	return GetFirstName() + separetor + GetLastName() + separetor + GetEmail() + separetor + GetPhone() + separetor + _AccountNumber + separetor + std::to_string(_Balance);
}

void BankClient::FromLine(std::string Line, const std::string& separetor)
{
	size_t pos = 0;
	std::vector<std::string> vData = BaseLib::String::Split(Line, separetor);
	
	if (vData.size() == 6)
	{
		SetFirstName(vData[0]);
		SetLastName(vData[1]);
		SetEmail(vData[2]);
		SetPhone(vData[3]);
		_AccountNumber = vData[4];
		SetBalance(std::stod(vData[5]));
	}
}

BankClient BankClient::getEmptyClient()
{
	return BankClient("", "", "", "", "", 0);
}

bool BankClient::Deposit(double Amount)
{
	if (IsEmpty())
		return false;
	else
	{
		_Balance += Amount;
		return true;
	}
}

bool BankClient::Withdraw(double Amount)
{
	if (Amount > _Balance || IsEmpty())
		return false;
	else
	{
		Deposit(-Amount);
		return true;
	}
}

bool BankClient::Transfer(double Amount, BankClient& distanceClient, const std::string& userName)
{
	if (Withdraw(Amount))
	{
		distanceClient.Deposit(Amount);
		_RegisterTranferLog(Amount, distanceClient, userName);
		return true;
	}
	return false;
}

void BankClient::_RegisterTranferLog(double amount, const BankClient& distanceClient, const std::string& userName)
{
	Repository<RegisterTransferLog> repo(Repository<RegisterTransferLog>::GetStandard_RegisterTransferLogFileName());

	RegisterTransferLog transferRegister = RegisterTransferLog(BaseLib::Date::GetCurrnetDate(), BaseLib::Time::GetCurrentTime(),
		this->GetAccountNumber(), distanceClient.GetAccountNumber(), amount, userName);

	repo.Add(transferRegister);
}

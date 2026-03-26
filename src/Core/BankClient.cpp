#include "BankClient.h"
#include "BaseLib/String.h"

#include <vector>

BankClient::BankClient(const std::string& FirstName, const std::string& LastName, const std::string& Email,
	const std::string& Phone, const std::string& AccountNumber, double Balance)
	: Person(FirstName, LastName, Email, Phone)
{
	_AccountNumber = AccountNumber;
	_Balance = Balance;
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
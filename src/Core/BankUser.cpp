#include "BankUser.h"
#include "BaseLib/String.h"

#include <vector>

BankUser::BankUser(const std::string& FirstName, const std::string& LastName, const std::string& Email, 
	const std::string& Phone, const std::string& UserName, const std::string& Password, int Permissions)
	: Person(FirstName, LastName, Email, Phone)
{
	_UserName = UserName;
	SetPassword(Password);
	SetPermissions(Permissions);
}

void BankUser::AddPermission(enPermissions Permission)
{
	if (enPermissions::eAdmin)
		_Permissions = enPermissions::eAdmin;

	_Permissions += Permission;
}

std::string BankUser::ToLine(const std::string& separetor) const
{
	return GetFirstName() + separetor + GetLastName() + separetor + GetEmail() + separetor + 
		GetPhone() + separetor + _UserName + separetor + _Password + separetor + std::to_string(_Permissions);
}

void BankUser::FromLine(std::string Line, const std::string& separetor)
{
	std::vector<std::string> vData = BaseLib::String::Split(Line, separetor);

	SetFirstName(vData[0]);
	SetLastName(vData[1]);
	SetEmail(vData[2]);
	SetPhone(vData[3]);
	_UserName = vData[4];
	SetPassword(vData[5]);
	SetPermissions(std::stoi(vData[6]));
}

BankUser BankUser::getEmptyUser()
{
	return BankUser("", "", "", "", "", "", 0);
}

bool BankUser::HasPermission(enPermissions PermissionRequired) const
{
	return (_Permissions & PermissionRequired) == PermissionRequired;
}

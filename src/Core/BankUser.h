#pragma once
#include <iostream>

#include "Person.h"
#include "IPersistable.h"

class BankUser : public Person, public IPersistable
{
private:
	std::string _UserName;
	std::string _Password;
	int _Permissions = 0;

public:
	enum enPermissions {
		eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64
	};

	BankUser() = default;

	BankUser(const std::string& FirstName, const std::string& LastName, const std::string& Email,
		const std::string& Phone, const std::string& UserName, const std::string& Password, int Permissions = 0);

	//void SetUserName(std::string UserName) { _UserName = UserName; }
	std::string GetUserName() const { return _UserName; }

	void SetPassword(std::string Password) { _Password = Password; }
	void AddPermission(enPermissions Permission);
	std::string GetPassword() const { return _Password; }

	void SetPermissions(int Permissions) { _Permissions = Permissions; }
	int GetPermissions() const { return _Permissions; }

	std::string ToLine(const std::string& separetor = "#//#") const override;
	void FromLine(std::string Line, const std::string& separetor = "#//#") override;

	std::string GetKey() const override { return _UserName; }
	
	bool IsEmpty() const { return _UserName == ""; }
	static BankUser getEmptyUser();

	bool HasPermission(enPermissions PermissionRequired) const;
};


#pragma once
#include <iostream>

#include "Person.h"
#include "IPersistable.h"

class BankUser : public Person, public IPersistable
{
private:
	std::string _UserName;
	std::string _Password;

public:
	BankUser() = default;

	BankUser(const std::string& FirstName, const std::string& LastName, const std::string& Email,
		const std::string& Phone, const std::string& UserName, const std::string& Password);

	//void SetUserName(std::string UserName) { _UserName = UserName; }
	std::string GetUserName() const { return _UserName; }

	void SetPassword(std::string Password) { _Password = Password; }
	std::string GetPassword() const { return _Password; }

	std::string ToLine(const std::string& separetor = "#//#") const override;
	void FromLine(std::string Line, const std::string& separetor = "#//#") override;

	std::string GetKey() const override { return _UserName; }
	
	bool IsEmpty() const { return _UserName == ""; }
};


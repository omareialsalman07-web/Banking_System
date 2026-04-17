#pragma once

#include "IPersistable.h"
#include "BankUser.h"

class UserLogRegister : public IPersistable
{
private:
	std::string _DateTime = "";
	BankUser _User;

public:
	UserLogRegister() = default;
	UserLogRegister(const BankUser& User);

	std::string ToLine(const std::string& separetor = "#//#") const override;
	void FromLine(std::string Line, const std::string& separetor = "#//#") override;
	inline std::string GetKey() const override { return _DateTime; }
	bool IsEmpty() const override { return _User.IsEmpty(); }

	std::string GetDateTime() const { return _DateTime; }
	void SetDateTime(const std::string& DateTime_String) { _DateTime = DateTime_String; }

	const BankUser& GetUser() const { return _User; }
	void setUser(const BankUser& User) { _User = User; }
};
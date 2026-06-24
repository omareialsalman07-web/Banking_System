#pragma once
#include <iostream>


#include "IPersistable.h"
#include "Person.h"

class BankClient : public Person, public IPersistable
{
private:
	std::string _AccountNumber;
	double _Balance = 0;

public:
	BankClient() = default;

	BankClient(const std::string& FirstName, const std::string& LastName, const std::string& Email, 
		const std::string& Phone, const std::string& AccountNumber, double Balance);
	
	std::string GetAccountNumber() const { return _AccountNumber; }
	
	void SetBalance(double Balance) { _Balance = Balance; }
	double GetBalance() const { return _Balance; }
	
	std::string ToLine(const std::string& separetor = "#//#") const override;
	void FromLine(std::string Line, const std::string& separetor = "#//#") override;
	
	std::string GetKey() const override { return _AccountNumber; }

	bool IsEmpty() const override { return _AccountNumber == ""; }
	static BankClient getEmptyClient();

	bool Deposit(double Amount);
	bool Withdraw(double Amount);
	bool Transfer(double Amount, BankClient& distanceClient, const std::string& userName);

private:
	void _RegisterTranferLog(double amount, const BankClient& distanceClient, const std::string& userName);
};
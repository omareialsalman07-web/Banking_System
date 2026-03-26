#pragma once
#include <iostream>


#include "IPersistable.h"
#include "Person.h"

class BankClient : public Person, public IPersistable
{
private:
	std::string _AccountNumber;
	double _Balance;

public:
	BankClient(const std::string& FirstName, const std::string& LastName, const std::string& Email, 
		const std::string& Phone, const std::string& AccountNumber, double Balance);
	
	void SetAccountNumber(std::string AccountNumber) { _AccountNumber = AccountNumber; }
	std::string GetAccountNumber() { return _AccountNumber; }
	
	void SetBalance(double Balance) { _Balance = Balance; }
	double GetBalance() { return _Balance; }
	
	std::string ToLine(const std::string& separetor = "#//#") const override;
	void FromLine(std::string Line, const std::string& separetor = "#//#") override;
	
	std::string GetKey() const override { return _AccountNumber; }
};


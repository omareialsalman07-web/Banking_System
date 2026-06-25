#pragma once

#include "IPersistable.h"

class BankCurrency : public IPersistable
{
private:
	std::string m_CountryName;
	std::string m_CurrencyName;
	std::string m_CurrencyCode;
	float m_Rate = 0;

public:
	BankCurrency(const std::string& countryName, const std::string& currencyName, const std::string& currencyCode, float rate);

	std::string ToLine(const std::string& separetor = "#//#") const override;
	void FromLine(std::string Line, const std::string& separetor = "#//#") override;

	std::string GetKey() const override { return m_CountryName; }
	bool IsEmpty() const override { return m_CountryName.empty() || m_CurrencyName.empty() || m_CurrencyCode.empty(); }

	void SetRate(float newRate);
};
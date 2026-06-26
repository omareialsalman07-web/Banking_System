#include "BankCurrency.h"
#include <exception>
#include <vector>
#include <BaseLib/String.h>

BankCurrency::BankCurrency(const std::string& countryName, const std::string& currencyName, const std::string& currencyCode, float rate)
	: m_CountryName(countryName), m_CurrencyName(currencyName), m_CurrencyCode(currencyCode), m_Rate(rate)
{
}

std::string BankCurrency::ToLine(const std::string& separetor) const
{
	return 
		m_CountryName + separetor +
		m_CurrencyCode + separetor +
		m_CountryName + separetor +
		std::to_string(m_Rate);
}

void BankCurrency::FromLine(std::string Line, const std::string& separetor)
{
	std::vector<std::string> vData = BaseLib::String::Split(Line, separetor);

	m_CountryName = vData[0];
	m_CurrencyCode = vData[1];
	m_CurrencyName = vData[2];
	m_Rate = std::stof(vData[3]);
}

void BankCurrency::SetRate(float newRate)
{
	m_Rate = newRate;
}

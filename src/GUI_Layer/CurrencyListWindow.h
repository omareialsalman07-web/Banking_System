#pragma once

#include "BaseWindow.h"
#include <Core/BankCurrency.h>
#include <Core/Repository.h>
#include <vector>

class CurrencyListWindow : public BaseWindow
{
public:
	CurrencyListWindow(int index);

private:
	void Render() override;

	void _DrawUpdateCurrency();
	std::string _CurrencyCode;
	float _RateAmount = 0;
	void _UpdateCurrency();

	void _DrawCurrenciesList();

	Repository<BankCurrency> m_Repo;
	std::vector<BankCurrency> m_Currencies;
	void _LoadCurrencies();
};
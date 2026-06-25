#pragma once

#include "BaseWindow.h"
#include <Core/BankCurrency.h>
#include <vector>

class CurrencyListWindow : public BaseWindow
{
public:
	CurrencyListWindow(int index);

private:
	void Render() override;

	std::vector<BankCurrency> _Currencies;
	void _LoadCurrencies();
};
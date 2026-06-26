#pragma once

#include "BaseWindow.h"

#include <string>
#include <vector>


class CurrencyExchangeCalculatorWindow : public BaseWindow
{
private:
    float _Amount = 0.0f;
    int _FromCurrency = 0;
    int _ToCurrency = 0;

    std::vector<std::string> m_CurrensiesInfo;
    std::string _Result = "0.00";

public:
    CurrencyExchangeCalculatorWindow(int index);

private:
    void _LoadCurrenciesInfo();
    void _DrawCurrencyCombo(const char* label, int& selected);
    void DrawCalculatorCard();
    void DrawResultCard();

protected:
    void Render() override;
};
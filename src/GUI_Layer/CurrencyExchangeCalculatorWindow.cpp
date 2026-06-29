#include "CurrencyExchangeCalculatorWindow.h"

#include <BaseLib/String.h>

#include "Im_GUI.h"

CurrencyExchangeCalculatorWindow::CurrencyExchangeCalculatorWindow(int index)
    : BaseWindow("Currency Exchange Calculator " + std::to_string(index), true, ImGuiWindowFlags_NoCollapse),
    m_Repo(Repository<BankCurrency>::GetStandard_CurrenciesFileName())
{
    _LoadCurrenciesInfo();
}



void CurrencyExchangeCalculatorWindow::Render()
{
    DrawScreenHeader("Currency Exchange");

    ImGui::Spacing();
    ImGui::Spacing();

    float width = 420;
    ImGui::SetCursorPosX((ImGui::GetWindowWidth() - width) * 0.5f);

    ImGui::BeginChild("MainCard", ImVec2(width, 430), true);

    DrawCalculatorCard();

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();

    DrawResultCard();

    ImGui::EndChild();
}



void CurrencyExchangeCalculatorWindow::DrawCalculatorCard()
{
    ImGui::TextColored(ImVec4(0.2f, 0.8f, 1.0f, 1.0f), "Exchange Details");
    ImGui::Spacing();

    ImGui::Text("Amount");
    ImGui::PushItemWidth(-1);
    ImGui::InputFloat("##Amount", &_Amount, 0, 0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::Spacing();

    ImGui::Text("From");
    _DrawCurrencyCombo("##FromCurrency", _FromCurrency);

    ImGui::Spacing();
    if (ImGui::Button("Swap Currency", ImVec2(-1, 35)))
    {
        std::swap(_FromCurrency, _ToCurrency);
    }

    ImGui::Spacing();
    ImGui::Text("To");
    _DrawCurrencyCombo("##ToCurrency", _ToCurrency);

    ImGui::Spacing();
    ImGui::Spacing();

    if (ImGui::Button("Calculate Exchange", ImVec2(-1, 45)))
    {
        CalculateCurrency();
    }
}

void CurrencyExchangeCalculatorWindow::DrawResultCard()
{

    ImGui::TextColored(ImVec4(0.2f, 1.0f, 0.3f, 1.0f), "Conversion Result");

    ImGui::Spacing();
    ImGui::BeginChild("ResultBox", ImVec2(-1, 80), true);

    const char* title = "Exchange Result";
    float textWidth = ImGui::CalcTextSize(title).x;
    ImGui::SetCursorPosX((ImGui::GetWindowWidth() - textWidth) * 0.5f);
    ImGui::Text("%s", title);

    ImGui::SetCursorPosY(45);
    ImGui::TextColored(ImVec4(1, 1, 0.3f, 1), "%s", _Result.c_str());

    ImGui::EndChild();
}


void CurrencyExchangeCalculatorWindow::_DrawCurrencyCombo(const char* label, int& selected)
{
    std::vector<const char*> items;
    for (const std::string& currency : m_CurrensiesInfo)
    {
        items.push_back(currency.c_str());
    }

    ImGui::PushItemWidth(-1);
    ImGui::Combo(label, &selected, items.data(), static_cast<int>(items.size()));
    ImGui::PopItemWidth();
}

std::string CurrencyExchangeCalculatorWindow::GetCurrencyCodeFromStringInfo(const std::string& str)
{
    std::vector < std::string> vDate = BaseLib::String::Split(str, "-");
    return BaseLib::String::Trim(vDate[0]);
}

void CurrencyExchangeCalculatorWindow::CalculateCurrency()
{
    BankCurrency fromCurrency = m_Repo.Find(GetCurrencyCodeFromStringInfo(m_CurrensiesInfo[_FromCurrency]));
    if (fromCurrency.IsEmpty())
    {
        ShowError("Can't find from Currency!");
        return;
    }
    BankCurrency ToCurrency = m_Repo.Find(GetCurrencyCodeFromStringInfo(m_CurrensiesInfo[_ToCurrency]));
    if (fromCurrency.IsEmpty())
    {
        ShowError("Can't find to Currency!");
        return;
    }

    _Result = std::to_string(fromCurrency.Convert(_Amount, ToCurrency));
}

void CurrencyExchangeCalculatorWindow::_LoadCurrenciesInfo()
{
    std::vector<BankCurrency> vData = m_Repo.LoadAll();

    for (const BankCurrency& c : vData)
    {
        m_CurrensiesInfo.push_back(c.GetCurrencyCode() + " - " + c.GetCountryName());
    }

}
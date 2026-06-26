#include "CurrencyListWindow.h"

#include <string>
#include <BaseLib/String.h>
#include "Im_Gui.h"

CurrencyListWindow::CurrencyListWindow(int index) : BaseWindow("Currencies List : " + std::to_string(index)),
    m_Repo((Repository<BankCurrency>::GetStandard_CurrenciesFileName()))
{
	_LoadCurrencies();
}

void CurrencyListWindow::Render()
{
	DrawScreenHeader("Currencies List");

    _DrawUpdateCurrency();
    ImGui::Separator();
    _DrawCurrenciesList();
}

void CurrencyListWindow::_DrawUpdateCurrency()
{
    ImGui::Text("Currency Code : "); ImGui::SameLine();
    ImGui::InputText("##CurrencyCOde", &_CurrencyCode); ImGui::SameLine();
    
    ImGui::Text("New Rate : "); ImGui::SameLine();
    ImGui::InputFloat("##CurrencyRate", &_RateAmount); //ImGui::SameLine();
    if (ImGui::Button("Update", ImVec2(120,30)))
    {
        _UpdateCurrency();
    }

}

void CurrencyListWindow::_UpdateCurrency()
{
    if (_RateAmount < 0 || _CurrencyCode.empty())
    {
        ShowError("Fill all the Fields to update rate");
        return;
    }

    BankCurrency currency = m_Repo.Find(_CurrencyCode);
    if (currency.IsEmpty())
    {
        ShowError("Can't find currency with the following currency code : " + _CurrencyCode);
        return;
    }

    currency.SetRate(_RateAmount);
    if (m_Repo.Update(currency))
    {
        ShowMessage("Rate updated!");
    }
    else
    {
        ShowError("Something went wrong, can't update the rate!");
    }
}

void CurrencyListWindow::_DrawCurrenciesList()
{
    ImVec2 RefreshButtonSize = ImVec2(ImGui::GetWindowSize().x - 30, 30);
    if (ImGui::Button("Refresh", RefreshButtonSize))
    {
        _LoadCurrencies();
    }

    if (ImGui::BeginTable("ScoreTable", 4,
        ImGuiTableFlags_Borders | ImGuiTableFlags_Resizable))
    {
        ImGui::TableSetupColumn("Country Name");
        ImGui::TableSetupColumn("Currency Code");
        ImGui::TableSetupColumn("Currency Name");
        ImGui::TableSetupColumn("Rate");
        ImGui::TableHeadersRow();

        for (int i = 0; i < m_Currencies.size(); i++)
        {
            ImGui::TableNextRow();
            ImGui::TableSetColumnIndex(0); ImGui::Text("%s", m_Currencies[i].GetCountryName().c_str());
            ImGui::TableSetColumnIndex(1); ImGui::Text("%s", m_Currencies[i].GetCurrencyCode().c_str());
            ImGui::TableSetColumnIndex(2); ImGui::Text("%s", m_Currencies[i].GetCurrencyName().c_str());
            ImGui::TableSetColumnIndex(3); ImGui::Text("%.3f", m_Currencies[i].GetRate());
        }

        ImGui::EndTable();
    }
}

void CurrencyListWindow::_LoadCurrencies()
{   
    m_Currencies = m_Repo.LoadAll();
}

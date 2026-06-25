#include "CurrencyListWindow.h"

#include <Core/Repository.h>
#include <string>
#include "Im_Gui.h"

CurrencyListWindow::CurrencyListWindow(int index) : BaseWindow("Currencies List : " + std::to_string(index))
{
	_LoadCurrencies();
}

void CurrencyListWindow::Render()
{
	DrawScreenHeader("Currencies List");

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

        for (int i = 0; i < _Currencies.size(); i++)
        {
            ImGui::TableNextRow();
            ImGui::TableSetColumnIndex(0); ImGui::Text("%s", _Currencies[i].GetCountryName().c_str());
            ImGui::TableSetColumnIndex(1); ImGui::Text("%s", _Currencies[i].GetCurrencyCode().c_str());
            ImGui::TableSetColumnIndex(2); ImGui::Text("%s", _Currencies[i].GetCurrencyName().c_str());
            ImGui::TableSetColumnIndex(3); ImGui::Text("%.3f", _Currencies[i].GetRate());
        }

        ImGui::EndTable();
    }
}

void CurrencyListWindow::_LoadCurrencies()
{
    Repository<BankCurrency> repo(Repository<BankCurrency>::GetStandard_CurrenciesFileName());
    
    _Currencies = repo.LoadAll();
}

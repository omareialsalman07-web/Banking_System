#include "CurrenciesExtchangeWindow.h"
#include "Im_Gui.h"

#include<App/Application.h>
#include<Core/Repository.h>
#include<Core/BankCurrency.h>

#include "CurrencyListWindow.h"
#include "CurrencyExchangeCalculatorWindow.h"

CurrenciesExtchangeWindow::CurrenciesExtchangeWindow(int index) : BaseWindow("CurrenciesExtchange : " + std::to_string(index))
{}

void CurrenciesExtchangeWindow::Render()
{
	DrawScreenHeader("Currency Extchange");

	if (ImGui::Button("Currency List", ImVec2(ImGui::GetWindowSize().x - 30, 30)))
	{
		Application::GetInstance().CreateWindow(std::make_unique<CurrencyListWindow>(Application::GetInstance().GetWindowsCount()));
	}
	if (ImGui::Button("Currency Calculation", ImVec2(ImGui::GetWindowSize().x - 30, 30)))
	{
		Application::GetInstance().CreateWindow(std::make_unique<CurrencyExchangeCalculatorWindow>(Application::GetInstance().GetWindowsCount()));
	}
}

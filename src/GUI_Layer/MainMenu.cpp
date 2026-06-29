#include "MainMenu.h"

#include <App/Application.h>
#include "GUI_Layer.h"
#include "Im_Gui.h"


MainMenu::MainMenu() : BaseWindow("Main Menu", false)
{

}

void MainMenu::Render()
{
	DrawScreenHeader("Main Menu");

	_RenderMenuBar();

	ImGui::Text("Welcome, %s!", Application::GetInstance().GetCurrentUser().FullName().c_str());

	if (ImGui::Button("Client List", ImVec2(ImGui::GetWindowSize().x - 30, 30)))
	{
		Application::GetInstance().CreateWindow(std::make_unique<CleintListWindow>(Application::GetInstance().GetWindowsCount()));
	}
	if (ImGui::Button("Add New Client", ImVec2(ImGui::GetWindowSize().x - 30, 30)))
	{
		Application::GetInstance().CreateWindow(std::make_unique<AddClientWindow>(Application::GetInstance().GetWindowsCount()));
	}
	if (ImGui::Button("Transactions", ImVec2(ImGui::GetWindowSize().x - 30, 30)))
	{
		Application::GetInstance().CreateWindow(std::make_unique<TransactionsWindow>(Application::GetInstance().GetWindowsCount()));
	}
	if (ImGui::Button("Transfer Money Register", ImVec2(ImGui::GetWindowSize().x - 30, 30)))
	{
		Application::GetInstance().CreateWindow(std::make_unique<TranferRegisterWindow>(Application::GetInstance().GetWindowsCount()));
	}
	if (ImGui::Button("Currency Exchange", ImVec2(ImGui::GetWindowSize().x - 30, 30)))
	{
		Application::GetInstance().CreateWindow(std::make_unique<CurrenciesExtchangeWindow>(Application::GetInstance().GetWindowsCount()));
	}
	if (ImGui::Button("Manage Users Window", ImVec2(ImGui::GetWindowSize().x - 30, 30)))
	{
		Application::GetInstance().CreateWindow(std::make_unique<ManageUsersWindow>(Application::GetInstance().GetWindowsCount()));
	}

	if (ImGui::Button("Logout", ImVec2(ImGui::GetWindowSize().x - 30, 30)))
	{
		Logut();
	}
}

void MainMenu::_RenderMenuBar()
{
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Exit"))
            {
                Application::GetInstance().Terminate();
            }

            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Window"))
        {
            if (ImGui::BeginMenu("Client Management"))
            {
                if (ImGui::MenuItem("Clients List"))
                {
                    Application::GetInstance().CreateWindow(std::make_unique<CleintListWindow>(Application::GetInstance().GetWindowsCount()));
                }

                if (ImGui::MenuItem("Add Client"))
                {
                    if (ImGui::Button("Add New Client", ImVec2(ImGui::GetWindowSize().x - 30, 30)));
                }

                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("User Management"))
            {
                if (ImGui::MenuItem("Users List"))
                {
                    Application::GetInstance().CreateWindow(std::make_unique<UsersListWindow>(Application::GetInstance().GetWindowsCount()));
                }

                if (ImGui::MenuItem("Add User"))
                {
                    Application::GetInstance().CreateWindow(std::make_unique<AddUserWindow>(Application::GetInstance().GetWindowsCount()));
                }

                ImGui::EndMenu();
            }

            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Actions"))
        {
            if (ImGui::MenuItem("Transactions"))
            {
                Application::GetInstance().CreateWindow(std::make_unique<TransactionsWindow>(Application::GetInstance().GetWindowsCount()));
            }

            if (ImGui::MenuItem("Currencies List"))
            {
                Application::GetInstance().CreateWindow(std::make_unique<CurrencyListWindow>(Application::GetInstance().GetWindowsCount()));
            }

            if (ImGui::MenuItem("Currency Caluculator"))
            {
                Application::GetInstance().CreateWindow(std::make_unique<CurrencyExchangeCalculatorWindow>(Application::GetInstance().GetWindowsCount()));
            }

            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Log"))
        {
            if (ImGui::MenuItem("User Login Registery"))
            {
                Application::GetInstance().CreateWindow(std::make_unique<LogRegisterWindow>(Application::GetInstance().GetWindowsCount()));
            }
            if (ImGui::MenuItem("Money Transfere Registery"))
            {
                Application::GetInstance().CreateWindow(std::make_unique<TranferRegisterWindow>(Application::GetInstance().GetWindowsCount()));
            }

            ImGui::EndMenu();
        }


        ImGui::EndMainMenuBar();
    }
}

void MainMenu::Logut()
{
	Application::GetInstance().SetCurrentUser(BankUser::getEmptyUser());
	Application::GetInstance().SetAppState(Application::enApplicationState::eLoggedOut);
}

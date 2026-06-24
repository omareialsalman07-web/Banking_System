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
	if (ImGui::Button("Manage Users Window", ImVec2(ImGui::GetWindowSize().x - 30, 30)))
	{
		Application::GetInstance().CreateWindow(std::make_unique<ManageUsersWindow>(Application::GetInstance().GetWindowsCount()));
	}

	if (ImGui::Button("Logout", ImVec2(ImGui::GetWindowSize().x - 30, 30)))
	{
		Logut();
	}
}

void MainMenu::Logut()
{
	Application::GetInstance().SetCurrentUser(BankUser::getEmptyUser());
	Application::GetInstance().SetAppState(Application::enApplicationState::eLoggedOut);
}

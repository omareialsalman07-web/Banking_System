#include "MainMenu.h"

#include <App/Application.h>
#include "GUI_Layer.h"
#include "Im_Gui.h"


MainMenu::MainMenu(Application* app) : BaseWindow("Main Menu", false), _App(app)
{

}

void MainMenu::Render()
{
	DrawScreenHeader("Main Menu");

	ImGui::Text("Welcome, %s!", _App->GetCurrentUser().FullName().c_str());

	if (ImGui::Button("Client List", ImVec2(ImGui::GetWindowSize().x - 30, 30)))
	{
		_App->CreateWindow(std::make_unique<CleintListWindow>(_App->GetWindowsCount()));
	}
	if (ImGui::Button("Add New Client", ImVec2(ImGui::GetWindowSize().x - 30, 30)))
	{
		_App->CreateWindow(std::make_unique<AddClientWindow>(_App->GetWindowsCount()));
	}

	if (ImGui::Button("Logout", ImVec2(ImGui::GetWindowSize().x - 30, 30)))
	{
		Logut();
	}
}

void MainMenu::Logut()
{
	if (_App)
	{
		_App->SetCurrentUser(BankUser::getEmptyUser());
		_App->SetAppState(Application::enApplicationState::eLoggedOut);
	}
}

#include "LoginMenu.h"

#include "Im_Gui.h"
#include <App/Application.h>
#include <Core/BankUser.h>
#include <Core/Repository.h>


LoginMenu::LoginMenu(Application* app) : BaseWindow("Login Menu", false), _App(app)
{
}

void LoginMenu::Render()
{
	ImGui::Text("Username : "); ImGui::SameLine();
	ImGui::InputText("##Username", &_Username);
	ImGui::Text("Password : "); ImGui::SameLine();
	ImGui::InputText("##Password", &_Password, ImGuiInputTextFlags_Password);

	if (ImGui::Button("Login"))
	{
		Login();
	}
}

void LoginMenu::Login()
{
	Repository<BankUser> userRepo(Repository<BankUser>::GetStandard_UsersFileName());
	BankUser bu = userRepo.Find(_Username);
	if (!bu.IsEmpty() && bu.GetPassword() == _Password)
	{
		if (_App)
		{
			_App->SetCurrentUser(bu);
			_App->SetWindowToShow(Application::enWindowToShow::eMainMenu);
		}
	}
	else
	{
		ShowError("Invalid username or password.");
	}
}

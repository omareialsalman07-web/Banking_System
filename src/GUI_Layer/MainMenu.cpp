#include "MainMenu.h"

#include <App/Application.h>
#include "Im_Gui.h"


MainMenu::MainMenu(Application* app) : BaseWindow("Main Menu", false), _App(app)
{

}

void MainMenu::Render()
{
	DrawScreenHeader("Main Menu");

	ImGui::Text("Welcome, %s!", _App->GetCurrentUser().FullName().c_str());

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
		_App->SetWindowToShow(Application::enWindowToShow::eLoginMenu);
	}
}

#include "ManageUsersWindow.h"

#include <App/Application.h>
#include "Im_Gui.h"
#include "GUI_Layer.h"
#include <string>

ManageUsersWindow::ManageUsersWindow(int index, Application* app) : BaseWindow("Manage Users : " + std::to_string(index)),
		_App(app)
{
}

void ManageUsersWindow::Render()
{
	DrawScreenHeader("Manage Users");

	if (ImGui::Button("Users List", ImVec2(ImGui::GetWindowSize().x - 30, 30)))
	{
		if (_App)
		{
			_App->CreateWindow(std::make_unique<UsersListWindow>(_App->GetWindowsCount(), _App));
		}
	}
	if (ImGui::Button("Add New User", ImVec2(ImGui::GetWindowSize().x - 30, 30)))
	{
		ShowMessage("Not implemented yet");
	}
}

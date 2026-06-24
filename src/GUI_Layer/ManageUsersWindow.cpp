#include "ManageUsersWindow.h"

#include <App/Application.h>
#include "Im_Gui.h"
#include "GUI_Layer.h"
#include <string>

ManageUsersWindow::ManageUsersWindow(int index) : BaseWindow("Manage Users : " + std::to_string(index))
{
}

void ManageUsersWindow::Render()
{
	DrawScreenHeader("Manage Users");

	if (ImGui::Button("Users List", ImVec2(ImGui::GetWindowSize().x - 30, 30)))
	{
		Application::GetInstance().CreateWindow(std::make_unique<UsersListWindow>(Application::GetInstance().GetWindowsCount()));
	}
	if (ImGui::Button("Add New User", ImVec2(ImGui::GetWindowSize().x - 30, 30)))
	{
		Application::GetInstance().CreateWindow(std::make_unique<AddUserWindow>(Application::GetInstance().GetWindowsCount()));
	}
	if (ImGui::Button("Show Login Register", ImVec2(ImGui::GetWindowSize().x - 30, 30)))
	{
		Application::GetInstance().CreateWindow(std::make_unique<LogRegisterWindow>(Application::GetInstance().GetWindowsCount()));
	}
}
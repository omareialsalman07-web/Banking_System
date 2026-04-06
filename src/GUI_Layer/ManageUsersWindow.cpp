#include "ManageUsersWindow.h"

#include <App/Application.h>
#include "Im_Gui.h"
#include <string>

ManageUsersWindow::ManageUsersWindow(int index, Application* app) : BaseWindow("Manage Users : " + std::to_string(index)),
		_App(app)
{
}

void ManageUsersWindow::Render()
{
	DrawScreenHeader("Manage Users");

	if (ImGui::Button("Client List", ImVec2(ImGui::GetWindowSize().x - 30, 30)))
	{
		ShowMessage("Not implemented yet");
	}
	if (ImGui::Button("Add New Client", ImVec2(ImGui::GetWindowSize().x - 30, 30)))
	{
		ShowMessage("Not implemented yet");
	}
}

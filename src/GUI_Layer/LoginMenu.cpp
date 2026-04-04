#include "LoginMenu.h"

#include "Im_Gui.h"
#include <App/Application.h>
#include <Core/BankUser.h>
#include <Core/Repository.h>


LoginMenu::LoginMenu(Application* app) : BaseWindow("Login Menu", false, ImGuiWindowFlags_NoResize |
     ImGuiWindowFlags_NoDocking), _App(app)
{
}

void LoginMenu::Render()
{
    ImGuiViewport* viewport = ImGui::GetMainViewport();

    // Center the window
    ImVec2 windowSize = ImVec2(300, 200);
    ImGui::SetNextWindowPos(viewport->GetCenter(), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
    ImGui::SetWindowSize(windowSize);

    // --- Center content horizontally ---
    float contentWidth = 200.0f;
    float windowWidth = ImGui::GetWindowSize().x;
    float centerX = (windowWidth - contentWidth) * 0.5f;

    // Username
    ImGui::SetCursorPosX(centerX);
    ImGui::Text("Username");

    ImGui::SetCursorPosX(centerX);
    ImGui::PushItemWidth(contentWidth);
    ImGui::InputText("##username", &_Username);
    ImGui::PopItemWidth();

    ImGui::Spacing();

    // Password
    ImGui::SetCursorPosX(centerX);
    ImGui::Text("Password");

    ImGui::SetCursorPosX(centerX);
    ImGui::PushItemWidth(contentWidth);
    ImGui::InputText("##password", &_Password, ImGuiInputTextFlags_Password);
    ImGui::PopItemWidth();

    ImGui::Spacing();
    ImGui::Spacing();

    // Login Button (centered)
    float buttonWidth = 120.0f;
    ImGui::SetCursorPosX((windowWidth - buttonWidth) * 0.5f);

    if (ImGui::Button("Login", ImVec2(buttonWidth, 0)))
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
            _App->SetAppState(Application::enApplicationState::eLoggedIn);
		}
		ShowMessage("Login successful!");
	}
	else
	{
		ShowError("Invalid username or password.");
	}
}

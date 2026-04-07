#include "UsersListWindow.h"

#include "Im_Gui.h"
#include "GUI_Layer.h"
#include <App/Application.h>

UsersListWindow::UsersListWindow(int index, Application* App) : BaseWindow("Users List : " + std::to_string(index)),
    repo(Repository<BankUser>::GetStandard_UsersFileName())
{
	_App = App;
    _Users = _GetAllUsers();
}

void UsersListWindow::Render()
{
	DrawScreenHeader("Users List");
    _DrawUsersList();
}

void UsersListWindow::_DrawUsersList()
{
    DrawScreenHeader("User List");

    ImVec2 RefreshButtonSize = ImVec2(ImGui::GetWindowSize().x - 30, 30);

    if (ImGui::Button("Refresh", RefreshButtonSize))
    {
        _Users = _GetAllUsers();
    }

    if (ImGui::BeginTable("ScoreTable", 6,
        ImGuiTableFlags_Borders | ImGuiTableFlags_Resizable))
    {
        ImGui::TableSetupColumn("First Name");
        ImGui::TableSetupColumn("Last Name");
        ImGui::TableSetupColumn("Email");
        ImGui::TableSetupColumn("Phone");
        ImGui::TableSetupColumn("User Name");
        ImGui::TableSetupColumn("Password");
        ImGui::TableHeadersRow();

        for (int i = 0; i < _Users.size(); i++)
        {
            ImGui::TableNextRow();
            ImGui::TableSetColumnIndex(0); ImGui::Text("%s", _Users[i].GetFirstName().c_str());
            ImGui::TableSetColumnIndex(1); ImGui::Text("%s", _Users[i].GetLastName().c_str());
            ImGui::TableSetColumnIndex(2); ImGui::Text("%s", _Users[i].GetEmail().c_str());
            ImGui::TableSetColumnIndex(3); ImGui::Text("%s", _Users[i].GetPhone().c_str());
            ImGui::TableSetColumnIndex(4); ImGui::Text("%s", _Users[i].GetUserName().c_str());

            ImGui::TableSetColumnIndex(5);
            ImGui::Text("%s", _Users[i].GetPassword().c_str());
            ImGui::PushID(i);
            ImGui::SameLine();
            if (ImGui::Button("Change User"))
            {
                _ShowChangeUserPopup = true;
                if(_App)
                {
                    _App->CreateWindow(std::make_unique<UpdateUserWindow>("Update User : " + std::to_string(_App->GetWindowsCount()), &_Users[i], &_ShowChangeUserPopup));
				}
            }
            ImGui::SameLine();
            if (ImGui::Button("X"))
            {
                repo.Delete(_Users[i].GetUserName());
                _Users = _GetAllUsers(); // Refresh the list after 
                ShowMessage("User Deleted Successfully");
            }
            ImGui::PopID();
        }

        ImGui::EndTable();
    }
}

std::vector<BankUser> UsersListWindow::_GetAllUsers()
{
    if (_ShowChangeUserPopup)
    {
        ShowError("Close Update User Window Before Refreshing Users List");
        return _Users; // if the change user popup is open, return the current list of users without refreshing it from the file, to avoid losing unsaved changes
    }
	return repo.LoadAll();
}

#include "UsersListWindow.h"

#include "Im_Gui.h"

UsersListWindow::UsersListWindow(int index) : BaseWindow("Users List : " + std::to_string(index)),
    repo(Repository<BankUser>::GetStandard_UsersFileName())
{
}

void UsersListWindow::Render()
{
	DrawScreenHeader("Users List");
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
        ImGui::TableSetupColumn("Account Number");
        ImGui::TableSetupColumn("Balance");
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
            ImGui::Text("%s", _Users[i].GetPassword());
            ImGui::PushID(i);
            ImGui::SameLine();
            if (ImGui::Button("Change User"))
            {
                _ShowChangeUserPopup = true;

                _SelectedUser = &_Users[i];
            }
            if (ImGui::ColorButton("X", ImVec4(1.0f, 0.0f, 0.0f, 1)))
            {
                repo.Delete(_Users[i].GetUserName());
				_Users = _GetAllUsers(); // Refresh the list after deletion
            }
            ImGui::PopID();
        }

        ImGui::EndTable();
    }
}

void UsersListWindow::_GetUserDataFromSelectedUser()
{
    if (!_SelectedUser)
    {
        _UserData = stUserData();
        _IsUserDataLoaded = false;
        return;
    }

    _UserData.FirstName = _SelectedUser->GetFirstName();
    _UserData.LastName = _SelectedUser->GetLastName();
    _UserData.Email = _SelectedUser->GetEmail();
    _UserData.Phone = _SelectedUser->GetPhone();
    _UserData.UserName = _SelectedUser->GetUserName();
    _UserData.Password = _SelectedUser->GetPassword();
    _UserData.Permissions.value = _SelectedUser->GetPermissions();
    _IsUserDataLoaded = true;
}

void UsersListWindow::_SaveUser()
{
}

std::vector<BankUser> UsersListWindow::_GetAllUsers()
{
    if(_ShowChangeUserPopup)
		return _Users; // if the change user popup is open, return the current list of users without refreshing it from the file, to avoid losing unsaved changes

	return repo.LoadAll();
}

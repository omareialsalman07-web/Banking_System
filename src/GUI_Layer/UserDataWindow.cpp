#include "UserDataWindow.h"

#include "Im_Gui.h"
#include <Core/BankUser.h>

UserDataWindow::UserDataWindow(std::string Title, BankUser* User) : BaseWindow(Title)
{
    this->User = User;
}

void UserDataWindow::Render()
{
    ImGui::Begin("Change User", nullptr, ImGuiWindowFlags_NoDocking);

    if (!_IsUserDataLoaded)
        _GetUserDataFromSelectedUser();

    ImGui::Text("First Name : "); ImGui::SameLine();
    ImGui::InputText("##FirstName", &FirstName);

    ImGui::Text("Last Name : "); ImGui::SameLine();
    ImGui::InputText("##LastName", &LastName);

    ImGui::Text("Email : "); ImGui::SameLine();
    ImGui::InputText("##Email", &Email);

    ImGui::Text("Phone Number : "); ImGui::SameLine();
    ImGui::InputText("##PhoneNumber", &Phone);

    ImGui::Text("Password : "); ImGui::SameLine();
    ImGui::InputText("##Password", &Password);

    ImGui::Text("\t\tPermission : "); ImGui::SameLine();
    _DrawPermissionsCheckboxes();

    ImGui::End();
}

void UserDataWindow::_DrawPermissionsCheckboxes()
{

}

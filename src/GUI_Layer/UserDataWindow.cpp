#include "UserDataWindow.h"
#include "Im_Gui.h"
#include <Core/BankUser.h>

UserDataWindow::UserDataWindow(const std::string& title, BankUser* user, bool* bShowUserDataWindow)
    : BaseWindow(title), _User(user)
{
    if (bShowUserDataWindow)
    {
        *bShowUserDataWindow = true;
    }
}

UserDataWindow::~UserDataWindow()
{
    if (bShowUserDataWindow)
    {
        *bShowUserDataWindow = false;
    }
}

void UserDataWindow::Render()
{
    DrawScreenHeader("User Data");

    if (!_IsLoaded && _User)
    {
        LoadFromUser(_User);
        _IsLoaded = true;
    }

    ImGui::InputText("First Name", &UserData.FirstName);
    ImGui::InputText("Last Name", &UserData.LastName);
    ImGui::InputText("Email", &UserData.Email);
    ImGui::InputText("Phone", &UserData.Phone);
    ImGui::InputText("Password", &UserData.Password);

    ImGui::BeginDisabled(!CanEditUserName());
    ImGui::InputText("Username", &UserData.UserName);
    ImGui::EndDisabled();

    ImGui::Separator();
    ImGui::Text("Permissions:");
    _DrawPermissionsCheckboxes();

    ImGui::Separator();

    if (ImGui::Button("Save", ImVec2(120, 0)))
    {
        LoadToUser();
        OnSubmit();
    }
    ImGui::SameLine();
    if (ImGui::Button("Cancle", ImVec2(120, 0)))
    {
        Close();
    }
}

void UserDataWindow::_DrawPermissionsCheckboxes()
{
    ImGui::Checkbox("Admin", &Permissions.bAdmin);

    if (!Permissions.bAdmin)
    {
        ImGui::Checkbox("List Clients", &Permissions.bListClients);
        ImGui::Checkbox("Add New Client", &Permissions.bAddNewClient);
        ImGui::Checkbox("Delete Client", &Permissions.bDeleteClient);
        ImGui::Checkbox("Update Clients", &Permissions.bUpdateClients);
        ImGui::Checkbox("Find Client", &Permissions.bFindClient);
        ImGui::Checkbox("Transactions", &Permissions.bTransactions);
        ImGui::Checkbox("Manage Users", &Permissions.bManageUsers);
    }
}

int UserDataWindow::_BuildPermissionsMask() const
{
    int mask = 0;

    if (Permissions.bAdmin) mask |= BankUser::eAdmin;
    if (Permissions.bListClients) mask |= BankUser::pListClients;
    if (Permissions.bAddNewClient) mask |= BankUser::pAddNewClient;
    if (Permissions.bDeleteClient) mask |= BankUser::pDeleteClient;
    if (Permissions.bUpdateClients) mask |= BankUser::pUpdateClients;
    if (Permissions.bFindClient) mask |= BankUser::pFindClient;
    if (Permissions.bTransactions) mask |= BankUser::pTranactions;
    if (Permissions.bManageUsers) mask |= BankUser::pManageUsers;

    return mask;
}

void UserDataWindow::LoadFromUser(BankUser* user)
{
    if (!user) return;

    UserData.FirstName = user->GetFirstName();
    UserData.LastName = user->GetLastName();
    UserData.Email = user->GetEmail();
    UserData.Phone = user->GetPhone();
    UserData.UserName = user->GetUserName();
    UserData.Password = user->GetPassword();

    int perms = user->GetPermissions();

    Permissions.bAdmin = (perms & BankUser::eAdmin);
    Permissions.bListClients = (perms & BankUser::pListClients);
    Permissions.bAddNewClient = (perms & BankUser::pAddNewClient);
    Permissions.bDeleteClient = (perms & BankUser::pDeleteClient);
    Permissions.bUpdateClients = (perms & BankUser::pUpdateClients);
    Permissions.bFindClient = (perms & BankUser::pFindClient);
    Permissions.bTransactions = (perms & BankUser::pTranactions);
    Permissions.bManageUsers = (perms & BankUser::pManageUsers);
}

void UserDataWindow::LoadToUser()
{
    if (_User)
    {
        _User->SetFirstName(UserData.FirstName);
        _User->SetLastName(UserData.LastName);
        _User->SetEmail(UserData.Email);
        _User->SetPhone(UserData.Phone);
        _User->SetPassword(UserData.Password);
        _User->SetPermissions(_BuildPermissionsMask());
    }
}

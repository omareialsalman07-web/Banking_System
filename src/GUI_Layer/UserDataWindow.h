#pragma once
#include "BaseWindow.h"
#include <string>

struct stUserData
{
    std::string FirstName;
    std::string LastName;
    std::string Email;
    std::string Phone;
    std::string UserName;
    std::string Password;
};

struct stPermission
{
    bool bAdmin = false;
    bool bListClients = false;
    bool bAddNewClient = false;
    bool bDeleteClient = false;
    bool bUpdateClients = false;
    bool bFindClient = false;
    bool bTransactions = false;
    bool bManageUsers = false;
};

class BankUser;

class UserDataWindow : public BaseWindow
{
public:
    UserDataWindow(const std::string& title, class BankUser* user = nullptr, bool* bShowUserDataWindow = nullptr);
    virtual ~UserDataWindow();

protected:
    virtual void Render() override;
    virtual void OnSubmit() = 0; // 🔥 key for extensibility

    void LoadFromUser(BankUser* user);
    void LoadToUser();

protected:
    stUserData UserData;

    stPermission Permissions;

    virtual bool CanEditUserName() const { return true; }

	BankUser* GetUser() const { return _User; }

private:
    void _DrawPermissionsCheckboxes();
    int _BuildPermissionsMask() const;

    bool _IsLoaded = false;
    BankUser* _User = nullptr;

    bool* bShowUserDataWindow = nullptr;
};
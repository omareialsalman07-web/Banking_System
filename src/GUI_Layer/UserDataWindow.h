#pragma once
#include "BaseWindow.h"

#include <iostream>

struct stPermission
{
	int value;

	bool bAdmin;
	bool bListClients;
	bool bAddNewClient;
	bool bDeleteClient;
	bool bUpdateClients;
	bool bFindClient;
	bool bTransactions;
	bool bManageUsers;

	stPermission() : value(0), bAdmin(false), bListClients(false), bAddNewClient(false), bDeleteClient(false),
		bUpdateClients(false), bFindClient(false), bTransactions(false), bManageUsers(false) {
	}
};

class UserDataWindow : public BaseWindow
{
public:
	UserDataWindow(std::string Title, class BankUser* User);
	~UserDataWindow() = default;

protected:
	virtual void Render() override;

	std::string FirstName;
	std::string LastName;
	std::string Email;
	std::string Phone;
	std::string UserName;
	std::string Password;

	stPermission Permissions = stPermission();

	BankUser* User = nullptr;

	void _DrawPermissionsCheckboxes();

	bool _IsUserDataLoaded = false;
	void _GetUserDataFromSelectedUser();
};


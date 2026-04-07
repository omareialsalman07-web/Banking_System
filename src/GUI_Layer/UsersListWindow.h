#pragma once
#include "BaseWindow.h"

#include <Core/BankUser.h>
#include <Core/Repository.h>

#include <iostream>
#include <vector>
#include <string>

class UsersListWindow : public BaseWindow
{
public:
	UsersListWindow(int index, class Application* App);
	~UsersListWindow() = default;

private:
	void Render() override;

	void _DrawUsersList();

	bool _ShowChangeUserPopup = false;

	Repository<BankUser> repo;
	std::vector<BankUser> _Users;
	std::vector<BankUser> _GetAllUsers();

	Application* _App;
};


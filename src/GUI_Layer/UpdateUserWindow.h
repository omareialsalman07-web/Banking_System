#pragma once

#include "UserDataWindow.h"

class UpdateUserWindow : public UserDataWindow
{
public:
	UpdateUserWindow(const std::string& title, class BankUser* user, bool* bShowUserDataWindow = nullptr);
	virtual ~UpdateUserWindow() = default;

private:
	virtual void OnSubmit() override;
	virtual bool CanEditUserName() const override { return false; }
};


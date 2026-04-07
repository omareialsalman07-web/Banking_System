#pragma once

#include "AddUserWindow.h"
#include "UserDataWindow.h"
#include <iostream>

class AddUserWindow : public UserDataWindow
{
public:
	AddUserWindow(int index);
	~AddUserWindow() = default;

private:
	virtual void OnSubmit() override;
	virtual bool CanEditUserName() const override { return true; }
};


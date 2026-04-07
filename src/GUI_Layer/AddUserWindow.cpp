#include "AddUserWindow.h"
#include <Core/BankUser.h>
#include <Core/Repository.h>

AddUserWindow::AddUserWindow(int index) : UserDataWindow("Add New User Window : " + std::to_string(index))
{
}

void AddUserWindow::OnSubmit()
{
	BankUser bu("", "", "", "", UserData.UserName, "", 0);
	LoadToUser(&bu);

	Repository<BankUser> repo(Repository<BankUser>::GetStandard_UsersFileName());
	if (repo.Add(bu))
	{
		ShowMessage("Add New User Successfully!");
	}
	else
	{
		ShowError("Can't Add User!");
	}
	
}

#include "UpdateUserWindow.h"

#include <Core/BankUser.h>
#include <Core/Repository.h>

UpdateUserWindow::UpdateUserWindow(int index, BankUser* user, bool* bShowUserDataWindow) : 
	UserDataWindow("Uppdate User Window : " + std::to_string(index), user, bShowUserDataWindow)
{

}

void UpdateUserWindow::OnSubmit()
{
	if (GetUser() == nullptr)
	{
		ShowError("No user loaded to update.");
		return;
	}

	LoadToUser(GetUser());
	Repository<BankUser> userRepo(Repository<BankUser>::GetStandard_UsersFileName());
	if (userRepo.Update(*GetUser()))
	{
		ShowMessage("User updated successfully.");
	}
	else
	{
		ShowError("Failed to update user. User may not exist.");
	}
}

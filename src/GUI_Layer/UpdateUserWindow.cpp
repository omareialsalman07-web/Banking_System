#include "UpdateUserWindow.h"

#include <Core/BankUser.h>
#include <Core/Repository.h>

UpdateUserWindow::UpdateUserWindow(const std::string& title, BankUser* user, bool* bShowUserDataWindow) : UserDataWindow(title, user, bShowUserDataWindow)
{

}

void UpdateUserWindow::OnSubmit()
{
	if (GetUser() == nullptr)
	{
		ShowError("No user loaded to update.");
		return;
	}

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

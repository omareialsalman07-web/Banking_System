#include <iostream>

#include "Core/Repository.h"
#include "Core/BankUser.h"
#include <vector>

int main()
{
	Repository<BankUser> userRepo("USERS.txt");

	BankUser user = userRepo.Find("AB07");

	if (!user.IsEmpty())
	{
		std::cout << "This User has permission to list clients: " << (user.HasPermission(BankUser::pListClients) ? "Yes" : "No") << std::endl;
		std::cout << "This User has permission to add new clients: " << (user.HasPermission(BankUser::pAddNewClient) ? "Yes" : "No") << std::endl;
		std::cout << "This User has permission to delete clients: " << (user.HasPermission(BankUser::pDeleteClient) ? "Yes" : "No") << std::endl;
		std::cout << "This User has permission to update clients: " << (user.HasPermission(BankUser::pUpdateClients) ? "Yes" : "No") << std::endl;
		std::cout << "This User has permission to transaction: " << (user.HasPermission(BankUser::pTranactions) ? "Yes" : "No") << std::endl;
		std::cout << "This User has permission to find client: " << (user.HasPermission(BankUser::pFindClient) ? "Yes" : "No") << std::endl;
		std::cout << "This User has permission to manage users: " << (user.HasPermission(BankUser::pManageUsers) ? "Yes" : "No") << std::endl;
	}

	return 0;
}
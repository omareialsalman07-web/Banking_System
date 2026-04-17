#include <iostream>

#include "Core/Repository.h"
#include "Core/BankUser.h"
#include "Core/UserLogRegister.h"
#include <vector>

int main()
{
	/*Repository<BankUser> repo("USERS.txt");

	BankUser bu = repo.Find("AB07");

	if (!bu.IsEmpty()) {
		Repository<UserLogRegister> repo2("LogRegisters.txt");
		UserLogRegister ul(bu);
		if (repo2.Add(ul))
		{
			std::cout << "Added";
		}
	}
	else
	{
		std::cout << "Empty ";
	}*/

	Repository<UserLogRegister> repo2("LogRegisters.txt");
	std::vector<UserLogRegister> ul = repo2.LoadAll();

	for (auto& u : ul)
	{
		std::cout << u.ToLine() << std::endl;
	}

	return 0;
}
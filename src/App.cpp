#include <iostream>

#include "Core/Repository.h"
#include "Core/BankClient.h"
#include <vector>

int main()
{
	Repository<BankClient> clientRepo("CLIENTS.txt");

	BankClient client1("Omar", "Ali", "O@gmail.com", "0123456789", "A101", 1000.0);

	clientRepo.Add(client1);

	std::cout << client1.ToLine() << std::endl;

	return 0;
}
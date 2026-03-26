#include <iostream>

#include "Core/Repository.h"
#include "Core/BankClient.h"
#include <vector>

int main()
{
	Repository<BankClient> clientRepo("CLIENTS.txt");

	BankClient client = clientRepo.Find("A101");

	client.Withdraw(1000);

	clientRepo.Update(client);

	return 0;
}
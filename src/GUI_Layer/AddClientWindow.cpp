#include "AddClientWindow.h"

#include "Im_Gui.h"
#include <Core/Repository.h>
#include <Core/BankCLient.h>
#include <string>

AddClientWindow::AddClientWindow(int index) : ClientDataWidnow("Add Client " + std::to_string(index))
{

}

void AddClientWindow::OnSubmit()
{
	Repository<BankClient> repo(Repository<BankClient>::GetStandard_ClientsFileName());

	BankClient bc("", "", "", "", ClientData.AccountNumber, 0);
	LoadToClient(&bc);

	if (repo.Add(bc))
	{
		ShowMessage("Added New Client Successfully!");
	}
	else
	{
		ShowError("Can't add new client! Make sure you fill all the fields and the account number is not existed with anoter client.");
	}
}
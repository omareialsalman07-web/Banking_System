#include "UpdateClientWindow.h"

#include <Core/BankClient.h>
#include <Core/Repository.h>
#include <string>

UpdateClientWindow::UpdateClientWindow(int index, BankClient* Client, bool* bShowChangeClientPopup)
	: ClientDataWidnow("Update Client Window : " + std::to_string(index), Client, bShowChangeClientPopup)
{
}

void UpdateClientWindow::OnSubmit()
{
	Repository<BankClient> repo(Repository<BankClient>::GetStandard_ClientsFileName());

	LoadToClient(GetClient());

	if (repo.Update(*GetClient()))
	{
		ShowMessage("Updated Client Data Successfully");
	}
	else
	{
		ShowError("Can't Update Client Date");
	}
}

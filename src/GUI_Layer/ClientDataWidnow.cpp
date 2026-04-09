#include "ClientDataWidnow.h"

#include "Im_Gui.h"
#include <Core/BankClient.h>

ClientDataWidnow::ClientDataWidnow(const std::string& Title, BankClient* client, bool* bShowChangeClientPopup)
	: BaseWindow(Title), _bShowChangeClientPopup(bShowChangeClientPopup), _Client(client)
{
	if (_bShowChangeClientPopup)
	{
		*_bShowChangeClientPopup = true;
	}
}

ClientDataWidnow::~ClientDataWidnow()
{
	if (_bShowChangeClientPopup)
	{
		*_bShowChangeClientPopup = false;
	}
}

void ClientDataWidnow::Render()
{
    DrawScreenHeader("Client Data");

    if (!_IsLoaded && _Client)
    {
        LoadFromClient(_Client);
        _IsLoaded = true;
    }

    ImGui::InputText("First Name", &ClientData.FirstName);
    ImGui::InputText("Last Name", &ClientData.LastName);
    ImGui::InputText("Email", &ClientData.Email);
    ImGui::InputText("Phone", &ClientData.Phone);
    ImGui::InputDouble("Balance", &ClientData.Balance);

    ImGui::BeginDisabled(!CanEditAccountNumber());
    ImGui::InputText("Clientname", &ClientData.AccountNumber);
    ImGui::EndDisabled();

    ImGui::Separator();

    if (ImGui::Button("Save", ImVec2(120, 0)))
    {
        OnSubmit();
    }
    ImGui::SameLine();
    if (ImGui::Button("Cancle", ImVec2(120, 0)))
    {
        Close();
    }
}

void ClientDataWidnow::LoadFromClient(BankClient* client)
{
    if (!client) return;

    ClientData.FirstName = client->GetFirstName();
    ClientData.LastName = client->GetLastName();
    ClientData.Email = client->GetEmail();
    ClientData.Phone = client->GetPhone();
    ClientData.AccountNumber = client->GetAccountNumber();
    ClientData.Balance = client->GetBalance();

    _IsLoaded = true;
}
void ClientDataWidnow::LoadToClient(BankClient* client)
{
    if (!client) return;

    client->SetFirstName(ClientData.FirstName);
    client->SetLastName(ClientData.LastName);
    client->SetEmail(ClientData.Email);
    client->SetPhone(ClientData.Phone);
    client->SetBalance(ClientData.Balance);
}

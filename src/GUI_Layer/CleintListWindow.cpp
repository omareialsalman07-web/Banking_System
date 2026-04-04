#include "CleintListWindow.h"

#include <Core/Repository.h>
#include <string>
#include "Im_Gui.h"

CleintListWindow::CleintListWindow(int index) : BaseWindow("Client List : " + std::to_string(index))
{
	_Clients = _GetAllClients();
    std::cout << _Clients[0].GetFirstName();

}

void CleintListWindow::Render()
{
	_DrawClientList();
    if(_ShowChangeClientPopup)
        _DrawChangeClientWindow();
}

void CleintListWindow::_DrawClientList()
{
    DrawScreenHeader("Client List");

    ImVec2 RefreshButtonSize = ImVec2(ImGui::GetWindowSize().x - 30, 30);

    if (ImGui::Button("Refresh", RefreshButtonSize))
    {
        _Clients = _GetAllClients();
    }

    if (ImGui::BeginTable("ScoreTable", 6,
        ImGuiTableFlags_Borders | ImGuiTableFlags_Resizable))
    {
        ImGui::TableSetupColumn("First Name");
        ImGui::TableSetupColumn("Last Name");
        ImGui::TableSetupColumn("Email");
        ImGui::TableSetupColumn("Phone");
        ImGui::TableSetupColumn("Account Number");
        ImGui::TableSetupColumn("Balance");
        ImGui::TableHeadersRow();

        for (int i = 0; i < _Clients.size(); i++)
        {
            ImGui::TableNextRow();
            ImGui::TableSetColumnIndex(0); ImGui::Text("%s", _Clients[i].GetFirstName().c_str());
            ImGui::TableSetColumnIndex(1); ImGui::Text("%s", _Clients[i].GetLastName().c_str());
            ImGui::TableSetColumnIndex(2); ImGui::Text("%s", _Clients[i].GetEmail().c_str());
            ImGui::TableSetColumnIndex(3); ImGui::Text("%s", _Clients[i].GetPhone().c_str());
            ImGui::TableSetColumnIndex(4); ImGui::Text("%s", _Clients[i].GetAccountNumber().c_str());

            ImGui::TableSetColumnIndex(5);
            ImGui::Text("%.3f", _Clients[i].GetBalance());
			ImGui::PushID(i);
            ImGui::SameLine(); 
            if(ImGui::Button("Change Cleint"))
            {
                _ShowChangeClientPopup = true;

				_SelectedClient = &_Clients[i];
            }
			ImGui::PopID();
        }

        ImGui::EndTable();
    }
}

void CleintListWindow::_DrawChangeClientWindow()
{
    if(!_SelectedClient)
		return;

	std::string header = "Change Client : " + std::to_string(_Clients.size());
	DrawScreenHeader(header.c_str());
	ImGui::Begin("Change Client", nullptr, ImGuiWindowFlags_NoDocking);

	if (!_IsClientDataLoaded)
        _GetClientDataFromSelectedClient();

	ImGui::Text("First Name : "); ImGui::SameLine();
	ImGui::InputText("##FirstName", &_ClientData.FirstName);

	ImGui::Text("Last Name : "); ImGui::SameLine();
	ImGui::InputText("##LastName", &_ClientData.LastName);

    ImGui::Text("Email : "); ImGui::SameLine();
    ImGui::InputText("##Email", &_ClientData.Email);

    ImGui::Text("Phone Number : "); ImGui::SameLine();
    ImGui::InputText("##PhoneNumber", &_ClientData.Phone);

    ImGui::Text("Balance : "); ImGui::SameLine();
    ImGui::InputDouble("##Balance", &_ClientData.Balance);

    if (ImGui::Button("Save Changes"))
    {
        _SaveClient();
        _ShowChangeClientPopup = false;
        _IsClientDataLoaded = false;
    }
    ImGui::SameLine();
    if (ImGui::Button("Cancel"))
    {
        _ShowChangeClientPopup = false;
        _IsClientDataLoaded = false;
    }

	ImGui::End();
}

void CleintListWindow::_GetClientDataFromSelectedClient()
{
    if (!_SelectedClient)
    {
        _ClientData = stClientData();
		_IsClientDataLoaded = false;
		return;
    }

    _ClientData.FirstName = _SelectedClient->GetFirstName();
    _ClientData.LastName = _SelectedClient->GetLastName();
    _ClientData.Email = _SelectedClient->GetEmail();
    _ClientData.Phone = _SelectedClient->GetPhone();
    _ClientData.AccountNumber = _SelectedClient->GetAccountNumber();
    _ClientData.Balance = _SelectedClient->GetBalance();
    _IsClientDataLoaded = true;
}

void CleintListWindow::_SaveClient()
{
	if (_ClientData.FirstName == "" || _ClientData.LastName == "" || _ClientData.Email == "" || _ClientData.Phone == "" || _ClientData.AccountNumber == "")
    {
        ShowError("All fields are required");
        return;
    }

	if (_ClientData.AccountNumber != _SelectedClient->GetAccountNumber())
    {
        ShowError("Account Number can't be changed");
        return;
    }

    if (_SelectedClient)
    {
		_SelectedClient->SetFirstName(_ClientData.FirstName);
		_SelectedClient->SetLastName(_ClientData.LastName);
		_SelectedClient->SetEmail(_ClientData.Email);
		_SelectedClient->SetPhone(_ClientData.Phone);
		_SelectedClient->SetBalance(_ClientData.Balance);

        Repository<BankClient> repo(Repository<BankClient>::GetStandard_ClientsFileName());
        if(repo.Update(*_SelectedClient))
		    ShowMessage("Client updated successfully.");
        else
			ShowError("Failed to update client!");
    }
}

std::vector<BankClient> CleintListWindow::_GetAllClients()
{
	if (_ShowChangeClientPopup) // if the change client popup is open, Don't refresh the clients list to avoid losing the pointer that is used to edit the client
		return _Clients;

    Repository <BankClient> repo(Repository<BankClient>::GetStandard_ClientsFileName());
    return repo.LoadAll();
}
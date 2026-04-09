#include "CleintListWindow.h"

#include <Core/Repository.h>
#include <string>
#include "Im_Gui.h"
#include "GUI_Layer.h"
#include <App/Application.h>

CleintListWindow::CleintListWindow(int index, Application* app) : BaseWindow("Client List : " + std::to_string(index)),
    _App(app)
{
	_Clients = _GetAllClients();
}

void CleintListWindow::Render()
{
	_DrawClientList();
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
                if (_App)
                {
                    _App->CreateWindow(std::make_unique<UpdateClientWindow>(_App->GetWindowsCount(), &_Clients[i], &_ShowChangeClientPopup));
                }
            }
			ImGui::PopID();
        }

        ImGui::EndTable();
    }
}



std::vector<BankClient> CleintListWindow::_GetAllClients()
{
	if (_ShowChangeClientPopup) // if the change client popup is open, Don't refresh the clients list to avoid losing the pointer that is used to edit the client
		return _Clients;

    Repository <BankClient> repo(Repository<BankClient>::GetStandard_ClientsFileName());
    return repo.LoadAll();
}
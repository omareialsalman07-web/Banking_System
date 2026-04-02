#include "CleintListWindow.h"

#include <Core/Repository.h>
#include <string>
#include "Im_Gui.h"

CleintListWindow::CleintListWindow(int index) : BaseWindow("Client List : " + std::to_string(index))
{
}

void CleintListWindow::Render()
{
	DrawScreenHeader("Client List");

	ImVec2 RefreshButtonSize = ImVec2(ImGui::GetWindowSize().x - 30, 30);

	if (ImGui::Button("Refresh", RefreshButtonSize))
	{

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
            ImGui::TableSetColumnIndex(0); ImGui::Text("%s", _Clients[i].GetFirstName());
            ImGui::TableSetColumnIndex(1); ImGui::Text("%s", _Clients[i].GetLastName());
            ImGui::TableSetColumnIndex(2); ImGui::Text("%s", _Clients[i].GetEmail());
            ImGui::TableSetColumnIndex(3); ImGui::Text("%s", _Clients[i].GetPhone());
            ImGui::TableSetColumnIndex(3); ImGui::Text("%s", _Clients[i].GetAccountNumber());
            ImGui::TableSetColumnIndex(4); ImGui::Text("%.3f", _Clients[i].GetBalance());
        }

        ImGui::EndTable();
    }
}

std::vector<BankClient> CleintListWindow::_GetAllClients()
{
	Repository <BankClient> repo(Repository<BankClient>::GetStandard_ClientsFileName());
    return repo.LoadAll();
}

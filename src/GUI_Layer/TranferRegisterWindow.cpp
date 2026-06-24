#include "TranferRegisterWindow.h"
#include "Im_Gui.h"
#include "../Core/Repository.h"

TranferRegisterWindow::TranferRegisterWindow(int index) : BaseWindow("Transfer Register : " + std::to_string(index))
{
    _LoadRegisterTransferLog();
}

void TranferRegisterWindow::Render()
{
    DrawScreenHeader("Login Register");

    ImVec2 RefreshButtonSize = ImVec2(ImGui::GetWindowSize().x - 30, 30);
    if (ImGui::Button("Refresh", RefreshButtonSize))
    {
        _LoadRegisterTransferLog();
    }

    if (ImGui::BeginTable("ScoreTable", 5,
        ImGuiTableFlags_Borders | ImGuiTableFlags_Resizable))
    {
        ImGui::TableSetupColumn("Date");
        ImGui::TableSetupColumn("From Acount Number");
        ImGui::TableSetupColumn("To Acount Number");
        ImGui::TableSetupColumn("Amount");
        ImGui::TableSetupColumn("User Name");
        ImGui::TableHeadersRow();

        for (int i = 0; i < _RegisterTransferLog.size(); i++)
        {
            ImGui::TableNextRow();
            ImGui::TableSetColumnIndex(0); ImGui::Text("%s", _RegisterTransferLog[i].GetDateTime().c_str());
            ImGui::TableSetColumnIndex(1); ImGui::Text("%s", _RegisterTransferLog[i].GetFromAccount().c_str());
            ImGui::TableSetColumnIndex(2); ImGui::Text("%s", _RegisterTransferLog[i].GetToAccount().c_str());
            ImGui::TableSetColumnIndex(3); ImGui::Text("%.3f", _RegisterTransferLog[i].GetAmount());
            ImGui::TableSetColumnIndex(4); ImGui::Text("%s", _RegisterTransferLog[i].GetUserName().c_str());
        }

        ImGui::EndTable();
    }
}

void TranferRegisterWindow::_LoadRegisterTransferLog()
{
    Repository<RegisterTransferLog> repo(Repository<RegisterTransferLog>::GetStandard_RegisterTransferLogFileName());
    _RegisterTransferLog = repo.LoadAll();
}

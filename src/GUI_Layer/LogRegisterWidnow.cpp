#include "LogRegisterWidnow.h"
#include "Im_Gui.h"
#include <Core/Repository.h>

LogRegisterWindow::LogRegisterWindow(int index) : BaseWindow("Log Register : " + std::to_string(index))
{
    _LoadUserLogRegisters();
}

void LogRegisterWindow::Render()
{
	DrawScreenHeader("Login Register");

	ImVec2 RefreshButtonSize = ImVec2(ImGui::GetWindowSize().x - 30, 30);
	if (ImGui::Button("Refresh", RefreshButtonSize))
	{
		_LoadUserLogRegisters();
	}

    if (ImGui::BeginTable("ScoreTable", 2,
        ImGuiTableFlags_Borders | ImGuiTableFlags_Resizable))
    {
        ImGui::TableSetupColumn("Date");
        ImGui::TableSetupColumn("User Name");
        ImGui::TableHeadersRow();

        for (int i = 0; i < _UserLogRegisters.size(); i++)
        {
            ImGui::TableNextRow();
            ImGui::TableSetColumnIndex(0); ImGui::Text("%s", _UserLogRegisters[i].GetDateTime().c_str());
            ImGui::TableSetColumnIndex(1); ImGui::Text("%s", _UserLogRegisters[i].GetUserName().c_str());
        }

        ImGui::EndTable();
    }
}

void LogRegisterWindow::_LoadUserLogRegisters()
{
    Repository<UserLogRegister> repo(Repository<UserLogRegister>::GetStandard_LogRegisterFileName());
    _UserLogRegisters = repo.LoadAll();
}

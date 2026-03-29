#include "BaseWindow.h"

#include "GUI_Layer/Im_GUI.h"
#include <string>

BaseWindow::BaseWindow(const std::string& title, bool canBeClosed, int ImWindowFlags)
	: _Title(title), _isOpen(true), CanBeClosed(canBeClosed), imWindowFlags(ImWindowFlags)
{
}

void BaseWindow::Run()
{
    if (!_isOpen)
        return;

    if (!ImGui::Begin(_Title.c_str(), (CanBeClosed? &_isOpen : nullptr), (ImGuiWindowFlags)imWindowFlags))
    {
        ImGui::End();
        return;
    }

    Render();
    _RenderPopups();

    ImGui::End();
}

void BaseWindow::DrawScreenHeader(const char* text)
{
    ImVec2 textSize = ImGui::CalcTextSize(text);

    float x = (ImGui::GetWindowSize().x - textSize.x) * 0.5f;
    float y = 20.0f;

    ImGui::SetCursorPos(ImVec2(x, y));
    ImGui::TextUnformatted(text);
    

    ImGui::Separator();
}

void BaseWindow::ShowError(const std::string& message)
{
    _ErrorMessage = message;
    _ShowErrorPopup = true;
}

void BaseWindow::ShowMessage(const std::string& message)
{
    _InfoMessage = message;
    _ShowInfoPopup = true;
}

void BaseWindow::_RenderPopups()
{
    if (_ShowErrorPopup)
    {
        ImGui::OpenPopup("Error");
    }

    if (_ShowInfoPopup)
    {
        ImGui::OpenPopup("Message");
    }

    // -------- Error Popup --------
    if (ImGui::BeginPopupModal("Error", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
    {
        ImGui::TextColored(ImVec4(1, 0, 0, 1), "%s", _ErrorMessage.c_str());
        ImGui::Separator();

        if (ImGui::Button("OK", ImVec2(120, 0)))
        {
            ImGui::CloseCurrentPopup();
            _ShowErrorPopup = false;
        }

        ImGui::EndPopup();
    }

    if (ImGui::BeginPopupModal("Message", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
    {
        ImGui::TextColored(ImVec4(0, 1, 0, 1), "%s", _InfoMessage.c_str());
        ImGui::Separator();

        if (ImGui::Button("OK", ImVec2(120, 0)))
        {
            ImGui::CloseCurrentPopup();
            _ShowInfoPopup = false;
        }

        ImGui::EndPopup();
    }
}
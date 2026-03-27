#include "Console.h"

#include <GUI_Layer/Im_Gui.h>

void Console::AddLog(const std::string& message)
{
    logs.push_back(message);
}

void Console::Clear()
{
    logs.clear();
}

void Console::Render(bool* open)
{
    ImGui::Begin("Console", open);

    if (ImGui::Button("Clear"))
        Clear();

    ImGui::Separator();

    ImGui::BeginChild("Scrolling");

    for (const auto& log : logs)
        ImGui::Text("%s", log.c_str());

    ImGui::EndChild();
    ImGui::End();
}
#pragma once
#include <vector>
#include <string>

class Console
{
public:
    void AddLog(const std::string& message);
    void Clear();
    void Render(bool* open);

private:
    std::vector<std::string> logs;
};
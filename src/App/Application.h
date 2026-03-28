#pragma once
#include <GLFW/glfw3.h>
#include "Console.h"
#include <Core/BankUser.h>
#include <iostream>
#include <memory>

class Application
{
public:
    enum enWindowToShow
    {
        eMainMenu = 0,
        eLoginMenu = 1
    };

    Application();
    ~Application();

    void Run();

private:
    void Init();
    void Shutdown();

    void BeginFrame();
    void EndFrame();

    void RenderDockspace();
    void RenderMenuBar();

private:
    GLFWwindow* window;

    bool showConsole = true;
    Console console;
    int counter = 0;

    std::unique_ptr<class MainMenu> mainMenu;
    std::unique_ptr<class LoginMenu> loginMenu;

    enWindowToShow WindowToShow;

    void RenderCurrentWindow();

    BankUser CurrentUser;

public:
    void SetWindowToShow(enWindowToShow window);

    const BankUser& GetCurrentUser() const { return CurrentUser; } // read-only
    void SetCurrentUser(const BankUser& user) { CurrentUser = user; }
};
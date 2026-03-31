#pragma once
#include "Console.h"
#include <Core/BankUser.h>
#include <iostream>
#include <vector>
#include <memory>

class Application
{
public:
    enum enApplicationState
    {
        eLoggedIn = 0,
        eLoggedOut = 1
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
    void RenderWindows();
    void RenderSub_Windows();


    struct GLFWwindow* window;

    bool showConsole = true;
    Console console;
    int counter = 0;

    std::unique_ptr<class MainMenu> mainMenu;
    std::unique_ptr<class LoginMenu> loginMenu;

    enApplicationState _AppState;


    BankUser CurrentUser;

	std::vector<std::unique_ptr<class BaseWindow>> vSubWindwos;

public:
    void SetAppState(enApplicationState appState);

    const BankUser& GetCurrentUser() const { return CurrentUser; } // read-only
    void SetCurrentUser(const BankUser& user) { CurrentUser = user; }

    void CreateWindow(std::unique_ptr<BaseWindow> window);
	inline int GetWindowsCount() const { return static_cast<int>(vSubWindwos.size()); }
};
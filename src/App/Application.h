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

private:
    Application();
    ~Application();

    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;

public:
    static Application& GetInstance();

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

private:
    struct GLFWwindow* window = nullptr;
    bool showConsole = true;
    Console console;
    int counter = 0;

    std::unique_ptr<class MainMenu> mainMenu;
    std::unique_ptr<class LoginMenu> loginMenu;

    enApplicationState _AppState;

    BankUser CurrentUser;

    std::vector<std::unique_ptr<class BaseWindow>> vSubWindwos;

    unsigned int _LoginAttempsCount = 3;

public:
    void SetAppState(enApplicationState appState);
    const BankUser& GetCurrentUser() const { return CurrentUser; }
    void SetCurrentUser(const BankUser& user) { CurrentUser = user; }
    void CreateWindow(std::unique_ptr<BaseWindow> window);
    inline int GetWindowsCount() const { return static_cast<int>(vSubWindwos.size()); }
    void TakeLoginAttemp() { --_LoginAttempsCount; }

    inline unsigned int GetLoginAttempsCount() const { return _LoginAttempsCount; }
};
#pragma once
#include <GLFW/glfw3.h>
#include "Console.h"
#include <iostream>

class Application
{
public:
    enum enWindowToShow { eMainMenu = 0, eLoginMenu = 1 };

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

	enWindowToShow WindowToShow;
	void RenderCurrentWindow();

public:
	inline void SetWindowToShow(enWindowToShow window) { WindowToShow = window; } 
};
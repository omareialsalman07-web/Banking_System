#pragma once
#include <GLFW/glfw3.h>
#include "Console.h"

class Application
{
public:
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
};
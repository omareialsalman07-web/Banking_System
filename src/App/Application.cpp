#include "Application.h"

#include <GLFW/glfw3.h>
#include <GUI_Layer/Im_Gui.h>
#include "GUI_Layer/MainMenu.h"
#include "GUI_Layer/LoginMenu.h"

Application::Application()
{
    Init();

	mainMenu = std::make_unique<MainMenu>(this);
	loginMenu = std::make_unique<LoginMenu>(this);

    SetAppState(enApplicationState::eLoggedOut);
	CurrentUser = BankUser::getEmptyUser();
}

Application::~Application()
{
    Shutdown();
}

void Application::Init()
{
    glfwInit();

    window = glfwCreateWindow(1280, 720, "Mini Editor", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    // ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    console.AddLog("Application started");
}

void Application::Shutdown()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
}

void Application::BeginFrame()
{
    glfwPollEvents();

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void Application::EndFrame()
{
    ImGui::Render();

    int w, h;
    glfwGetFramebufferSize(window, &w, &h);
    glViewport(0, 0, w, h);
    glClear(GL_COLOR_BUFFER_BIT);

    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    ImGuiIO& io = ImGui::GetIO();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        GLFWwindow* backup = glfwGetCurrentContext();
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        glfwMakeContextCurrent(backup);
    }

    glfwSwapBuffers(window);
}

void Application::RenderDockspace()
{
    ImGuiWindowFlags flags =
        ImGuiWindowFlags_MenuBar |
        ImGuiWindowFlags_NoTitleBar |
        ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoBringToFrontOnFocus |
        ImGuiWindowFlags_NoNavFocus;

    const ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->WorkPos);
    ImGui::SetNextWindowSize(viewport->WorkSize);
    ImGui::SetNextWindowViewport(viewport->ID);

    ImGui::Begin("DockSpace", nullptr, flags);

    ImGuiID dockspaceID = ImGui::GetID("DockSpaceID");
    ImGui::DockSpace(dockspaceID, ImVec2(0, 0), ImGuiDockNodeFlags_PassthruCentralNode);

    ImGui::End();
}

void Application::RenderMenuBar()
{
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Exit"))
                glfwSetWindowShouldClose(window, true);

            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Window"))
        {
            ImGui::MenuItem("Console", nullptr, &showConsole);
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Actions"))
        {
            if (ImGui::MenuItem("Add Log"))
            {
                counter++;
                console.AddLog("Log message #" + std::to_string(counter));
            }

            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }
}

void Application::RenderWindows()
{
    switch (_AppState)
    {
    case Application::eLoggedIn:
		mainMenu->Run();
        RenderSub_Windows();
        break;
    case Application::eLoggedOut:
        loginMenu->Run();
        break;
    }
}

void Application::RenderSub_Windows()
{
   vSubWindwos.erase(std::remove_if(vSubWindwos.begin(), vSubWindwos.end(),
	   [](const std::unique_ptr<BaseWindow>& window) { return !window->IsOpen(); }),
        vSubWindwos.end());

   for (int i = 0; i < vSubWindwos.size(); i++)
   {
       if (vSubWindwos[i].get()->IsOpen())
       {
           vSubWindwos[i].get()->Run();
       }
   }
}

void Application::Run()
{
    while (!glfwWindowShouldClose(window))
    {
        BeginFrame();

        RenderDockspace();
        RenderMenuBar();

        RenderWindows();

        if (showConsole)
            console.Render(&showConsole);


        EndFrame();
    }
}


void Application::SetAppState(enApplicationState appState)
{
	_AppState = appState;

	vSubWindwos.erase(vSubWindwos.begin(), vSubWindwos.end()); // Clear all sub-windows when changing state. We don't want to keep them around if we log out for example.
}

void Application::CreateWindow(std::unique_ptr<BaseWindow> window)
{
	vSubWindwos.push_back(std::move(window)); // std::move to avoid copying the unique_ptr, which is not allowed. We transfer ownership instead.
}

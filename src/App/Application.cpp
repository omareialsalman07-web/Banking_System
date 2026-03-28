#include "Application.h"

#include <GUI_Layer/Im_Gui.h>
#include "GUI_Layer/MainMenu.h"

Application::Application() : WindowToShow(enWindowToShow::eMainMenu)
{
    Init();

	mainMenu = std::make_unique<MainMenu>();
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
    ImGuiWindowFlags flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;

    const ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->WorkPos);
    ImGui::SetNextWindowSize(viewport->WorkSize);
    ImGui::SetNextWindowViewport(viewport->ID);

    flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;

    ImGui::Begin("DockSpace", nullptr, flags);

    ImGuiID dockspaceID = ImGui::GetID("DockSpaceID");
    ImGui::DockSpace(dockspaceID);

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

void Application::RenderCurrentWindow()
{
    switch (WindowToShow)
    {
    case Application::eMainMenu:
		mainMenu->Run();
        break;
    case Application::eLoginMenu:
        break;
    }
}

void Application::Run()
{
    while (!glfwWindowShouldClose(window))
    {
        BeginFrame();

        RenderDockspace();
        RenderMenuBar();

        RenderCurrentWindow();

        if (showConsole)
            console.Render(&showConsole);


        EndFrame();
    }
}
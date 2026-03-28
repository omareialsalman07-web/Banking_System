#pragma once

#include "BaseWindow.h"

class Application;

class MainMenu : public BaseWindow
{
public :
	MainMenu(Application* app);
	~MainMenu() = default;
	void Render() override;

private:
	Application* _App;
	
	void Logut();
};
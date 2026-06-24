#pragma once

#include "BaseWindow.h"

class Application;

class MainMenu : public BaseWindow
{
public :
	MainMenu();
	~MainMenu() = default;
	void Render() override;

private:
	void Logut();
};
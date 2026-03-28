#pragma once

#include "BaseWindow.h"

class MainMenu : public BaseWindow
{
public :
	MainMenu();
	~MainMenu() = default;
	void Render() override;
};
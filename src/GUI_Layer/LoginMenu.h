#pragma once
#include "BaseWindow.h"
#include <iostream>

class Application;

class LoginMenu : public BaseWindow
{
public:
	LoginMenu(Application* app);
	~LoginMenu() = default;

	void Render() override;

private:
	Application* _App;

	std::string _Username;
	std::string _Password;

	void Login();

};


#pragma once
#include "BaseWindow.h"
#include <iostream>

class Application;

class LoginMenu : public BaseWindow
{
public:
	LoginMenu();
	~LoginMenu() = default;

	void Render() override;

private:
	std::string _Username;
	std::string _Password;

	void Login();

};


#pragma once
#include "BaseWindow.h"
#include <iostream>

class ManageUsersWindow : public BaseWindow
{
public:
	ManageUsersWindow(int index, class Application* app);
	~ManageUsersWindow() = default;

private:
	void Render() override;
	Application* _App;
};


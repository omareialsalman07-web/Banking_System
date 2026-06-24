#pragma once
#include "BaseWindow.h"
#include <iostream>

class ManageUsersWindow : public BaseWindow
{
public:
	ManageUsersWindow(int index);
	~ManageUsersWindow() = default;

private:
	void Render() override;

};


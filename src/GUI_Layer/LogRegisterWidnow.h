#pragma once

#include "BaseWindow.h"
#include "../Core/UserLogRegister.h"
#include <vector>

class LogRegisterWindow : public BaseWindow
{
public:
	LogRegisterWindow(int index);

private:
	void Render() override;

	std::vector<UserLogRegister> _UserLogRegisters;
	void _LoadUserLogRegisters();
};
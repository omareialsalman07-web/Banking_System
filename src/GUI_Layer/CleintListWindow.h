#pragma once
#include "BaseWindow.h"

#include <Core/BankClient.h>
#include <iostream>
#include <vector>

class CleintListWindow : public BaseWindow
{
public:
	CleintListWindow(int index, class Application* app);
	~CleintListWindow() = default;

private:
	void Render() override;

	void _DrawClientList();
	bool _ShowChangeClientPopup = false;

	std::vector<BankClient> _Clients;
	std::vector<BankClient> _GetAllClients();

	Application* _App;
};


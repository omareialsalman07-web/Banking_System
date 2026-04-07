#pragma once
#include "BaseWindow.h"

#include <Core/BankClient.h>
#include <iostream>
#include <vector>

struct stClientData
{
	std::string FirstName;
	std::string LastName;
	std::string Email;
	std::string Phone;
	std::string AccountNumber;
	double Balance;

	stClientData() : FirstName(""), LastName(""), Email(""), Phone(""), AccountNumber(""), Balance(0.0) {}
};

class CleintListWindow : public BaseWindow
{
public:
	CleintListWindow(int index);
	~CleintListWindow() = default;

private:
	void Render() override;

	void _DrawClientList();
	bool _ShowChangeClientPopup = false;
	void _DrawChangeClientWindow();

	BankClient* _SelectedClient = nullptr;

	stClientData _ClientData;
	bool _IsClientDataLoaded = false;
	void _GetClientDataFromSelectedClient();
	void _SaveClient();

	std::vector<BankClient> _Clients;
	std::vector<BankClient> _GetAllClients();
};


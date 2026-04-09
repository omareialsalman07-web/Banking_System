#pragma once
#include "ClientDataWidnow.h"

#include <iostream>

class UpdateClientWindow : public ClientDataWidnow
{
public:
	UpdateClientWindow(int index, class BankClient* Client, bool* bShowChangeClientPopup);
	~UpdateClientWindow() = default;

private:
	void OnSubmit() override;

	bool CanEditAccountNumber() override { return false; }
};


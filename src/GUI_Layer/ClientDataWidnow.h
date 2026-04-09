#pragma once
#include "BaseWindow.h"

struct stClientData
{
	std::string FirstName;
	std::string LastName;
	std::string Email;
	std::string Phone;
	std::string AccountNumber;
	double Balance = 0;
};

class ClientDataWidnow : public BaseWindow
{
public:
	ClientDataWidnow(const std::string& Title, class BankClient* = nullptr, bool* bShowChangeClientPopup = nullptr);
	virtual ~ClientDataWidnow();

protected:
	virtual void Render() override;

	virtual void OnSubmit() = 0;
	virtual bool CanEditAccountNumber() { return true; }

	stClientData ClientData;

	void LoadFromClient(BankClient* client);
	void LoadToClient(BankClient* client);

	BankClient* GetClient() { return _Client; }

private:
	bool* _bShowChangeClientPopup;

	bool _IsLoaded = false;

	BankClient* _Client;
};


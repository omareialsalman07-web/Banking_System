#pragma once

#include "BaseWindow.h"
#include <iostream>

#include <Core/Repository.h>
#include <Core/BankCLient.h>

class TransactionsWindow : public BaseWindow
{
public:
	TransactionsWindow(int index);
	~TransactionsWindow() = default;

private:
	void Render() override;

	std::string _AccountNumber;
	double _Amount = 0;

	Repository<BankClient> _ClientsRepo;
	BankClient _TargetClient;

	void _DrawClientInfo();
	void _HandleTransaction();
};


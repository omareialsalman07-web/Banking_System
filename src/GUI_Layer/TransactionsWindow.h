#pragma once

#include "BaseWindow.h"

#include <string>

#include <Core/Repository.h>
#include <Core/BankCLient.h>

class TransactionsWindow : public BaseWindow
{
public:
    explicit TransactionsWindow(int index);
    ~TransactionsWindow() override = default;

private:
    void Render() override;

private:
    Repository<BankClient> _ClientsRepo;

    // Deposit / Withdraw
    std::string _AccountNumber;
    BankClient _TargetClient;
    double _TransactionAmount = 0.0;

    // Transfer
    std::string _FromAccountNumber;
    std::string _ToAccountNumber;

    BankClient _FromClient;
    BankClient _ToClient;

    double _TransferAmount = 0.0;

private:
    void _DrawTransactionSection();
    void _DrawTransferSection();

    void _HandleDeposit();
    void _HandleWithdraw();
    void _HandleTransfer();

    bool _FindClient(const std::string& accountNumber, BankClient& client);

    void _DrawClientInfo(const BankClient& client);

    void _ResetTransactionState();
    void _ResetTransferState();
};
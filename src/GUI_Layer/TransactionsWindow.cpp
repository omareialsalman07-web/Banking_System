#include "TransactionsWindow.h"

#include "Im_Gui.h"

TransactionsWindow::TransactionsWindow(int index)
    : BaseWindow("Transactions " + std::to_string(index))
    , _ClientsRepo(Repository<BankClient>::GetStandard_ClientsFileName())
{}

void TransactionsWindow::Render()
{
    DrawScreenHeader("Transactions Window");

    _DrawTransactionSection();

    ImGui::Separator();

    _DrawTransferSection();
}

bool TransactionsWindow::_FindClient(const std::string& accountNumber, BankClient& client)
{
    client = _ClientsRepo.Find(accountNumber);

    if (client.IsEmpty())
    {
        ShowError("Client Not Found");
        return false;
    }

    return true;
}

void TransactionsWindow::_DrawClientInfo(const BankClient& client)
{
    ImGui::Separator();

    ImGui::Text("Client Name: %s", client.FullName().c_str());
    ImGui::Text("Balance: %.2f", client.GetBalance());

    ImGui::Separator();
}

void TransactionsWindow::_DrawTransactionSection()
{
    ImGui::BeginChild(
        "TransactionSection",
        ImVec2(0, ImGui::GetWindowSize().y * 0.45f),
        true);

    ImGui::Text("Deposit / Withdraw");

    ImGui::Text("Account Number:");
    ImGui::SameLine();

    ImGui::InputText("##AccountNumber", &_AccountNumber);

    ImGui::SameLine();

    if (ImGui::Button("Search"))
    {
        _FindClient(_AccountNumber, _TargetClient);
    }

    if (!_TargetClient.IsEmpty())
    {
        _DrawClientInfo(_TargetClient);

        ImGui::InputDouble("Amount", &_TransactionAmount);

        if (ImGui::Button("Deposit"))
        {
            _HandleDeposit();
        }

        ImGui::SameLine();

        if (ImGui::Button("Withdraw"))
        {
            _HandleWithdraw();
        }
    }

    ImGui::EndChild();
}

void TransactionsWindow::_HandleDeposit()
{
    if (_TransactionAmount <= 0)
    {
        ShowError("Invalid Amount");
        return;
    }

    if (_TargetClient.Deposit(_TransactionAmount))
    {
        _ClientsRepo.Update(_TargetClient);
        ShowMessage("Deposit Successful");

        _ResetTransactionState();
    }
    else
    {
        ShowError("Deposit Failed");
    }
}

void TransactionsWindow::_HandleWithdraw()
{
    if (_TransactionAmount <= 0)
    {
        ShowError("Invalid Amount");
        return;
    }

    if (_TargetClient.Withdraw(_TransactionAmount))
    {
        _ClientsRepo.Update(_TargetClient);
        ShowMessage("Withdraw Successful");

        _ResetTransactionState();
    }
    else
    {
        ShowError("Withdraw Failed");
    }
}

void TransactionsWindow::_DrawTransferSection()
{
    ImGui::BeginChild(
        "TransferSection",
        ImVec2(0, 0),
        true);

    ImGui::Text("Transfer");

    //----------------------------------
    // FROM CLIENT
    //----------------------------------

    ImGui::Text("From Account:");
    ImGui::SameLine();

    ImGui::InputText("##FromAccount", &_FromAccountNumber);

    ImGui::SameLine();

    if (ImGui::Button("Search From"))
    {
        _FindClient(_FromAccountNumber, _FromClient);
    }

    if (!_FromClient.IsEmpty())
    {
        ImGui::Text("Source Client");
        _DrawClientInfo(_FromClient);
    }

    //----------------------------------
    // TO CLIENT
    //----------------------------------

    ImGui::Text("To Account:");
    ImGui::SameLine();

    ImGui::InputText("##ToAccount", &_ToAccountNumber);

    ImGui::SameLine();

    if (ImGui::Button("Search To"))
    {
        _FindClient(_ToAccountNumber, _ToClient);
    }

    if (!_ToClient.IsEmpty())
    {
        ImGui::Text("Destination Client");
        _DrawClientInfo(_ToClient);
    }

    //----------------------------------
    // TRANSFER
    //----------------------------------

    if (!_FromClient.IsEmpty() && !_ToClient.IsEmpty())
    {
        ImGui::InputDouble("Transfer Amount", &_TransferAmount);

        if (ImGui::Button("Transfer"))
        {
            _HandleTransfer();
        }
    }

    ImGui::EndChild();
}

void TransactionsWindow::_HandleTransfer()
{
    if (_TransferAmount <= 0)
    {
        ShowError("Invalid Amount");
        return;
    }

    if (_FromClient.GetAccountNumber() ==
        _ToClient.GetAccountNumber())
    {
        ShowError("Cannot transfer to same account");
        return;
    }

    bool withdrawn = _FromClient.Withdraw(_TransferAmount);

    if (!withdrawn)
    {
        ShowError("Insufficient Balance");
        return;
    }

    _ToClient.Deposit(_TransferAmount);

    _ClientsRepo.Update(_FromClient);
    _ClientsRepo.Update(_ToClient);

    ShowMessage("Transfer Successful");

    _ResetTransferState();
}

void TransactionsWindow::_ResetTransactionState()
{
    _TargetClient = BankClient::getEmptyClient();
    _TransactionAmount = 0.0;
    _AccountNumber.clear();
}

void TransactionsWindow::_ResetTransferState()
{
    _FromClient = BankClient::getEmptyClient();
    _ToClient = BankClient::getEmptyClient();

    _FromAccountNumber.clear();
    _ToAccountNumber.clear();

    _TransferAmount = 0.0;
}
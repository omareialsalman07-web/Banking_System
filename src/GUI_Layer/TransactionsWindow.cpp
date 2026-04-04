#include "TransactionsWindow.h"

#include "Im_Gui.h"
#include <string>

TransactionsWindow::TransactionsWindow(int index) : BaseWindow("Transactions " + std::to_string(index)), _ClientsRepo(Repository<BankClient>::GetStandard_ClientsFileName())
{
}

void TransactionsWindow::Render()
{
	DrawScreenHeader("Transactions Widnow");

	ImGui::Text("Account Number : "); ImGui::SameLine();
	ImGui::InputText("##AccountNumber", &_AccountNumber); ImGui::SameLine();
	if (ImGui::Button("Search", ImVec2(80, 30)))
	{
		if (_ClientsRepo.Find(_AccountNumber).IsEmpty())
			ShowError("Client Not Found");
		else
			_TargetClient = _ClientsRepo.Find(_AccountNumber);
	}

	if (!_TargetClient.IsEmpty())
	{
		_DrawClientInfo();
		_HandleTransaction();
	}
}

void TransactionsWindow::_DrawClientInfo()
{
	ImGui::Text("Client Name : %s", _TargetClient.FullName().c_str());
	ImGui::Text("Current Balance : %.2f", _TargetClient.GetBalance());
}

void TransactionsWindow::_HandleTransaction()
{
	ImGui::InputDouble("Amount", &_Amount);
	if (ImGui::Button("Deposit", ImVec2(80, 30)))
	{
		if (_TargetClient.Deposit(_Amount))
		{
			_ClientsRepo.Update(_TargetClient);
			ShowMessage("Deposit Successful");
		}
		else
			ShowError("Deposit Failed");
		_TargetClient = BankClient::getEmptyClient();
		_Amount = 0;
	}
	ImGui::SameLine();
	if (ImGui::Button("Withdraw", ImVec2(80, 30)))
	{
		if (_TargetClient.Withdraw(_Amount))
		{
			_ClientsRepo.Update(_TargetClient);
			ShowMessage("Withdraw Successful");
		}
		else
			ShowError("Withdraw Failed");
		_TargetClient = BankClient::getEmptyClient();
		_Amount = 0;
	}
}

#include "AddClientWindow.h"

#include "Im_Gui.h"
#include <Core/Repository.h>
#include <Core/BankCLient.h>
#include <string>

AddClientWindow::AddClientWindow(int index) : BaseWindow("Add Client " + std::to_string(index))
{

}

void AddClientWindow::Render()
{
	DrawScreenHeader("Add Client");

	ImVec2 size = ImVec2(ImGui::GetWindowSize().x - 30, ImGui::GetWindowSize().y - 30);
	ImGui::BeginChild("AddClientChild", size, true);

	ImGui::InputText("First Name : ", &_FirstName);
	ImGui::InputText("Last Name : ", &_LastName);
	ImGui::InputText("Email : ", &_Email);
	ImGui::InputText("Phone Number : ", &_PhoneNumber);
	ImGui::InputText("Account Number : ", &_AccountNumber);
	ImGui::InputDouble("Balance : ", &_Balance);

	if (ImGui::Button("Add Client", ImVec2(size.x - 100, 20)))
	{
		Close();
		_AddClient();
	}

	ImGui::EndChild();

}

void AddClientWindow::_AddClient()
{
	if (_FirstName.empty() || _LastName.empty() || _Email.empty() || _PhoneNumber.empty() || _AccountNumber.empty())
	{
		ShowError("Please fill in all fields.");
	}
	else
	{
		Repository<BankClient> repo(Repository<BankClient>::GetStandard_ClientsFileName());
		if (repo.Find(_AccountNumber).IsEmpty() != true)
		{
			ShowError("A client with this account number already exists.");
			return;
		}
		else
		{
			BankClient newClient(_FirstName, _LastName, _Email, _PhoneNumber, _AccountNumber, _Balance);
			if(repo.Add(newClient))
				ShowMessage("Client added successfully!");
			else
				ShowError("Failed to add client!");
		}
	}
}

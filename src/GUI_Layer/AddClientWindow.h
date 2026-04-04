#pragma once
#include "BaseWindow.h"

#include <iostream>

class AddClientWindow : public BaseWindow
{
public:
	AddClientWindow(int index);
	~AddClientWindow() = default;
	void Render() override;

private:
	std::string _FirstName;
	std::string _LastName;
	std::string _Email;
	std::string _PhoneNumber;
	std::string _AccountNumber;
	double _Balance = 0;

	void _AddClient();
};


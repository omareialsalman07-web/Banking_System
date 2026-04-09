#pragma once
#include "ClientDataWidnow.h"

#include <iostream>

class AddClientWindow : public ClientDataWidnow
{
public:
	AddClientWindow(int index);
	~AddClientWindow() = default;

private:
	void OnSubmit() override;
};


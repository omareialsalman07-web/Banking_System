#pragma once

#include "BaseWindow.h"

class CurrenciesExtchangeWindow : public BaseWindow
{
public:
	CurrenciesExtchangeWindow(int index);

private:
	void Render() override;
};
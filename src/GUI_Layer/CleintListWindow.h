#pragma once
#include "BaseWindow.h"

#include <iostream>

class CleintListWindow : public BaseWindow
{
public:
	CleintListWindow(int index);
	~CleintListWindow() = default;

private:
	void Render() override;
};


#pragma once

#include "BaseWindow.h"
#include <Core/RegisterTransferLog.h>
#include <vector>

class TranferRegisterWindow : public BaseWindow
{
public:
	TranferRegisterWindow(int index);

private:
	void Render() override;

	std::vector<RegisterTransferLog> _RegisterTransferLog;
	void _LoadRegisterTransferLog();
};
#include "CleintListWindow.h"

#include <string>
#include "Im_Gui.h"

CleintListWindow::CleintListWindow(int index) : BaseWindow("Client List : " + std::to_string(index))
{
}

void CleintListWindow::Render()
{
	DrawScreenHeader("Client List");


}

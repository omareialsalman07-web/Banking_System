#include "App/Application.h"

#include <Core/BankUser.h>
#include <Core/Repository.h>

int main()
{
    Application& app = Application::GetInstance();
    app.Run();

    return 0;
}
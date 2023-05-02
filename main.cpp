#include <iostream>
#include <windows.h>
#include <winbase.h>
#include <time.h>

#include "BudgetApp.h"

using namespace std;

int main()
{
    BudgetApp budgetApp("Users.xml", "Incomes.xml", "Expenses.xml");

    while (true)
    {
        if (!budgetApp.checkIfUserIsLoggedIn())
        {
            budgetApp.selectOptionFromMainMenu();
        }
        else
        {
            budgetApp.selectOptionFromUserMenu();
        }
    }

    return 0;
}

#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include <iostream>

#include "UserManager.h"
#include "TransactionManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class BudgetApp {
    UserManager userManager;
    TransactionManager *transactionManager;
    const string FILE_NAME_WITH_INCOMES;
    const string FILE_NAME_WITH_EXPENSES;

    void registerUser();
    void logInUser();
    void changeLoggedInUserPassword();
    void logOutUser();
    void addIncome();
    void addExpense();
    void showCurrentMonthBalance();
    void showLastMonthBalance();
    void showSelectedPeriodBalance();

public:
    BudgetApp(string fileNameWithUsers, string fileNameWithIncomes, string fileNameWithExpenses)
        : userManager(fileNameWithUsers), FILE_NAME_WITH_INCOMES(fileNameWithIncomes), FILE_NAME_WITH_EXPENSES(fileNameWithExpenses)
    {
        transactionManager = NULL;
    };
    ~BudgetApp()
    {
        delete transactionManager;
        transactionManager = NULL;
    };

    void selectOptionFromMainMenu();
    void selectOptionFromUserMenu();
    bool checkIfUserIsLoggedIn();
};

#endif

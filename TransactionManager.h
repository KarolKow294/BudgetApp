#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include <iostream>
#include <vector>
#include <conio.h>

#include "Income.h"
#include "Expense.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"
#include "AuxiliaryMethods.h"

using namespace std;

class TransactionManager {
    int ID_OF_LOGGED_IN_USER;
    vector <Income> incomes;
    vector <Expense> expenses;
    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;

    Income getNewIncomeData();

public:
    TransactionManager(string fileNameWithIncomes, string fileNameWithExpenses, int idOfLoggedInUser)
        : fileWithIncomes(fileNameWithIncomes), fileWithExpenses(fileNameWithExpenses), ID_OF_LOGGED_IN_USER(idOfLoggedInUser)
    {
        incomes = fileWithIncomes.loadLoggedUserIncomesFromFile(ID_OF_LOGGED_IN_USER);
        //expenses = fileWithExpenses.loadLoggedUserExpensesFromFile(ID_OF_LOGGED_IN_USER);
    };

    void addIncome();
};

#endif

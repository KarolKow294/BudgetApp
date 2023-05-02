#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include <iostream>
#include <vector>
#include <conio.h>
#include <algorithm>
#include <string>

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

    int loadDate();
    Income getNewIncomeData();
    Expense getNewExpenseData();
    void showBalance(int startDate, int endDate);

public:
    TransactionManager(int idOfLoggedInUser, string fileNameWithIncomes, string fileNameWithExpenses)
        : ID_OF_LOGGED_IN_USER(idOfLoggedInUser), fileWithIncomes(fileNameWithIncomes), fileWithExpenses(fileNameWithExpenses)
    {
        incomes = fileWithIncomes.loadLoggedUserIncomesFromFile(ID_OF_LOGGED_IN_USER);
        expenses = fileWithExpenses.loadLoggedUserExpensesFromFile(ID_OF_LOGGED_IN_USER);
    };

    void addIncome();
    void addExpense();
    void showCurrentMonthBalance();
    void showLastMonthBalance();
    void showSelectedPeriodBalance();
};

#endif

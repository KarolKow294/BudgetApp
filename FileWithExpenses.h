#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>

#include "XmlFile.h"
#include "Expense.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithExpenses : public XmlFile {
    int lastExpenseId;

    Expense getExpenseData();

public:
    FileWithExpenses(string fileNameWithUsers) : XmlFile(fileNameWithUsers) {
    lastExpenseId = 0;
    };

    int getLastExpenseId();
    bool addExpenseToFile(Expense expense);
    vector <Expense> loadLoggedUserExpensesFromFile(int idOfLoggedInUser);
};

#endif

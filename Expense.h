#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

#include "Amount.h"

using namespace std;

class Expense : public Amount {

public:
    Expense(int amountId = 0, int userId = 0, int date = 0, string item = "", double amount = 0.0) {};
};
#endif

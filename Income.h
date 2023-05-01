#ifndef INCOME_H
#define INCOME_H

#include <iostream>

#include "Amount.h"

using namespace std;

class Income : public Amount{

public:
    Income(int amountId = 0, int userId = 0, int date = 0, string item = "", double amount = 0.0) {};
};

#endif

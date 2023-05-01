#ifndef AMOUNT_H
#define AMOUNT_H

#include <iostream>

using namespace std;

class Amount {
    int amountId;
    int userId;
    int date;
    string item;
    double value;

public:
    void setAmountId(int newAmountId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setValue(double newValue);

    int getAmountId();
    int getUserId();
    int getDate();
    string getItem();
    double getValue();
};

#endif

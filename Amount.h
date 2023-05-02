#ifndef AMOUNT_H
#define AMOUNT_H

#include <iostream>

using namespace std;

class Amount {
    int amountId;
    int userId;
    int date;
    string item;
    double amount;

public:
    bool operator < (Amount &str) {
        return (date < str.date);
    }

    void setAmountId(int newAmountId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(double newAmount);

    int getAmountId();
    int getUserId();
    int getDate();
    string getItem();
    double getAmount();
};

#endif

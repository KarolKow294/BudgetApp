#include "Amount.h"

void Amount::setAmountId(int newAmountId) {
    if (newAmountId >= 0)
        amountId = newAmountId;
}

void Amount::setUserId(int newUserId) {
    userId = newUserId;
}

void Amount::setDate(int newDate) {
    date = newDate;
}

void Amount::setItem(string newItem) {
    item = newItem;
}

void Amount::setValue(double newValue) {
    value = newValue;
}

int Amount::getAmountId() {
    return amountId;
}

int Amount::getUserId() {
    return userId;
}

int Amount::getDate() {
    return date;
}

string Amount::getItem() {
    return item;
}

double Amount::getValue() {
    return value;
}

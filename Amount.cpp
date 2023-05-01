#include "Amount.h"

void Amount::setAmountId(int newAmountId) {
    if (newAmountId >= 0)
        amountId = newAmountId;
}

void Amount::setUserId(int newUserId) {
    userId = newUserId;
}

void Amount::setData(int newData) {
    data = newData;
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

int Amount::getData() {
    return data;
}

string Amount::getItem() {
    return item;
}

double Amount::getValue() {
    return value;
}

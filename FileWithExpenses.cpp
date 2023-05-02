#include "FileWithExpenses.h"

int FileWithExpenses::getLastExpenseId() {
    return lastExpenseId;
}

bool FileWithExpenses::addExpenseToFile(Expense expense) {
    bool fileExists = xml.Load(FILE_NAME);
    string date = AuxiliaryMethods::convertIntDateToStringWithDashes(expense.getDate());

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseId", expense.getAmountId());
    xml.AddElem("UserId", expense.getUserId());
    xml.AddElem("Date", date);
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount", AuxiliaryMethods::convertFloatToString(expense.getAmount()));

    if (!xml.Save(FILE_NAME)) {
        return false;
    }
    lastExpenseId++;
    return true;
}

Expense FileWithExpenses::getExpenseData() {
    Expense expense;

    xml.IntoElem();
    xml.ResetMainPos();
    xml.FindElem("ExpenseId");
    expense.setAmountId(atoi(MCD_2PCSZ(xml.GetData())));
    xml.FindElem("UserId");
    expense.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
    xml.FindElem("Date");
    expense.setDate(AuxiliaryMethods::convertStringDateToIntWithoutDashes(MCD_2PCSZ(xml.GetData())));
    xml.FindElem("Item");
    expense.setItem(MCD_2PCSZ(xml.GetData()));
    xml.FindElem("Amount");
    expense.setAmount(atof(MCD_2PCSZ(xml.GetData())));
    xml.OutOfElem();

    return expense;
}

vector <Expense> FileWithExpenses::loadLoggedUserExpensesFromFile(int idOfLoggedInUser) {
    Expense expense;
    vector <Expense> expenses;

    bool fileExists = xml.Load(FILE_NAME);

    if (fileExists) {
        xml.FindElem();
        xml.IntoElem();

        while (xml.FindElem("Expense")) {
            xml.FindChildElem("UserId");
            if (xml.GetChildData() == AuxiliaryMethods::convertIntToString(idOfLoggedInUser)) {
                expense = getExpenseData();
                expenses.push_back(expense);
                lastExpenseId = expense.getAmountId();
            }
        }
    }
    return expenses;
}

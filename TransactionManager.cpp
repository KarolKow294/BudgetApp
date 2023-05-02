#include "TransactionManager.h"

int TransactionManager::loadDate() {
   string date;

   while (true) {
        date = AuxiliaryMethods::loadLine();

        if (AuxiliaryMethods::checkIfDateIsCorrect(date)) {
            return AuxiliaryMethods::convertStringDateToIntWithoutDashes(date);
        }
        else {
            cout << "Wprowadzona data jest nieprawidlowa. Wprowadz date ponownie (yyyy-mm-dd): ";
        }
    }
}

Income TransactionManager::getNewIncomeData() {
    Income income;

    income.setAmountId(fileWithIncomes.getLastIncomeId() + 1);
    income.setUserId(ID_OF_LOGGED_IN_USER);

    cout << "Czy przychod ktory chcesz dodac dotyczy dnia dzisiejszego?" << endl;
    cout << "Potwierdz naciskajac klawisz 't': ";
        if (getch() == 't') {
            string date;

            date = AuxiliaryMethods::getCurrentDate();
            income.setDate(AuxiliaryMethods::convertStringDateToIntWithoutDashes(date));
            cout << endl << "Dzisiejsza data zostala pobrana." << endl;
        }
        else {
            cout << endl << "Podaj date (yyyy-mm-dd): ";
            income.setDate(loadDate());
        }

    cout << "Podaj zrodlo przychodu: ";
    income.setItem(AuxiliaryMethods::loadLine());

    cout << "Podaj wartosc: ";
    income.setAmount(AuxiliaryMethods::loadFloatNumber());

    return income;
}

Expense TransactionManager::getNewExpenseData() {
    Expense expense;

    expense.setAmountId(fileWithExpenses.getLastExpenseId() + 1);
    expense.setUserId(ID_OF_LOGGED_IN_USER);

    cout << "Czy wydatek ktory chcesz dodac dotyczy dnia dzisiejszego?" << endl;
    cout << "Potwierdz naciskajac klawisz 't': ";
        if (getch() == 't') {
            string date;

            date = AuxiliaryMethods::getCurrentDate();
            expense.setDate(AuxiliaryMethods::convertStringDateToIntWithoutDashes(date));
            cout << endl << "Dzisiejsza data zostala pobrana." << endl;
        }
        else {
            cout << endl << "Podaj date (yyyy-mm-dd): ";
            expense.setDate(loadDate());
        }

    cout << "Podaj cel wydatku: ";
    expense.setItem(AuxiliaryMethods::loadLine());

    cout << "Podaj wartosc: ";
    expense.setAmount(AuxiliaryMethods::loadFloatNumber());

    return expense;
}

void TransactionManager::addIncome() {
    Income income;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    income = getNewIncomeData();

    incomes.push_back(income);
    if (fileWithIncomes.addIncomeToFile(income))
        cout << endl << "Nowy przychod zostal dodany" << endl;
    else
        cout << endl << "Blad. Nie udalo sie dodac nowego przychodu do pliku." << endl;
    system("pause");
}

void TransactionManager::addExpense() {
    Expense expense;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl << endl;
    expense = getNewExpenseData();

    expenses.push_back(expense);
    if (fileWithExpenses.addExpenseToFile(expense))
        cout << endl << "Nowy wydatek zostal dodany" << endl;
    else
        cout << endl << "Blad. Nie udalo sie dodac nowego wydatku do pliku." << endl;
    system("pause");
}

void TransactionManager::showBalance(int startDate, int endDate) {
    double totalIncomes = 0;
    double totalExpenses = 0;

    sort(incomes.begin(), incomes.end());
    sort(expenses.begin(), expenses.end());

    system("cls");
    cout << " >>> Lista przychodow <<<" << endl << endl;
    for (auto& v : incomes) {
        if (v.getDate() >= startDate && v.getDate() <= endDate){
            cout << "Data:    " << AuxiliaryMethods::convertIntDateToStringWithDashes(v.getDate()) << endl;
            cout << "Zrodlo:  " << v.getItem() << endl;
            cout << "Wartosc: " << v.getAmount() << endl << endl;
            totalIncomes += v.getAmount();
        }
    }

    cout << " >>> Lista wydatkow <<<" << endl << endl;
    for (auto& v : expenses) {
        if (v.getDate() >= startDate && v.getDate() <= endDate){
            cout << "Data:    " << AuxiliaryMethods::convertIntDateToStringWithDashes(v.getDate()) << endl;
            cout << "Cel:     " << v.getItem() << endl;
            cout << "Wartosc: " << v.getAmount() << endl << endl;
            totalExpenses += v.getAmount();
        }
    }

    cout << "Suma przychodow: " << totalIncomes << endl;
    cout << "Suma wydatkow:   " << totalExpenses << endl;
    cout << "Bilans           " << totalIncomes - totalExpenses << endl;
    system("pause");
}

void TransactionManager::showCurrentMonthBalance() {
    string currentDate = AuxiliaryMethods::getCurrentDate();
    int currentYear = AuxiliaryMethods::convertStringToInt(currentDate.substr(0, 4));
    int currentMonth = AuxiliaryMethods::convertStringToInt(currentDate.substr(5, 2));
    int maxDaysInCurrentMonth = AuxiliaryMethods::specifyNumberOfDaysInMonth(currentYear, currentMonth);

    int startDate = currentYear * 10000 + currentMonth * 100 + 1;
    int endDate = currentYear * 10000 + currentMonth * 100 + maxDaysInCurrentMonth;

    showBalance(startDate, endDate);
}

void TransactionManager::showLastMonthBalance() {
    string currentDate = AuxiliaryMethods::getCurrentDate();
    int currentYear = AuxiliaryMethods::convertStringToInt(currentDate.substr(0, 4));
    int currentMonth = AuxiliaryMethods::convertStringToInt(currentDate.substr(5, 2));

    int lastMonthYear, lastMonth, maxDaysInLastMonth;

    if (currentMonth == 1) {
        lastMonthYear = currentYear - 1;
        lastMonth = 12;
    }
    else {
        lastMonthYear = currentYear;
        lastMonth = currentMonth - 1;
    }

    maxDaysInLastMonth = AuxiliaryMethods::specifyNumberOfDaysInMonth(lastMonthYear, lastMonth);

    int startDate = lastMonthYear * 10000 + lastMonth * 100 + 1;
    int endDate = lastMonthYear * 10000 + lastMonth * 100 + maxDaysInLastMonth;

    showBalance(startDate, endDate);
}

void TransactionManager::showSelectedPeriodBalance() {
    int startDate, endDate;

    cout << "Podaj date od ktorej wyswietlic bilans przychod i wydatkow (yyyy-mm-dd): ";
    startDate = loadDate();

    cout << "Podaj date do ktorej wyswietlic bilans przychod i wydatkow (yyyy-mm-dd): ";
    endDate = loadDate();

    if (startDate <= endDate)
        showBalance(startDate, endDate);
    else {
        cout << endl << "Nie udalo sie pokazac bilansu. Data poczatkowa jest wieksza od daty koncowej." << endl;
        system("pause");
    }
}

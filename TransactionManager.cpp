#include "TransactionManager.h"

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
            string date;

            cout << endl << "Podaj date (yyyy-mm-dd): ";
            date = AuxiliaryMethods::loadLine();

            while (true) {
                if (AuxiliaryMethods::checkIfDateIsCorrect(date)) {
                    income.setDate(AuxiliaryMethods::convertStringDateToIntWithoutDashes(date));
                    break;
                }
                else {
                    cout << "Wprowadzona data jest nieprawidlowa. Wprowadz date ponownie (yyyy-mm-dd): ";
                    date = AuxiliaryMethods::loadLine();
                }
            }
        }

    cout << "Podaj zrodlo przychodu: ";
    income.setItem(AuxiliaryMethods::loadLine());

    cout << "Podaj wartosc: ";
    income.setValue(AuxiliaryMethods::loadFloatNumber());

    return income;
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
        cout << endl << "Blad. Nie udalo sie dodac nowego adresata do pliku." << endl;
    //test
    cout << income.getAmountId() << income.getUserId() << income.getDate() << income.getItem() << income.getValue() << endl;
    system("pause");
}

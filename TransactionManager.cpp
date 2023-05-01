#include "TransactionManager.h"

Income TransactionManager::getNewIncomeData() {
    Income income;

    income.setAmountId(/*fileWithIncomes.getNewIncomeId()*/ + 1);
    income.setUserId(ID_OF_LOGGED_IN_USER);

    cout << "Czy przychod ktory chcesz dodac dotyczy dnia dzisiejszego?" << endl;
    cout << "Potwierdz naciskajac klawisz 't': ";
        if (getch() == 't') {
            string data;

            data = AuxiliaryMethods::getCurrentData();
            income.setData(AuxiliaryMethods::convertStringDataToIntWithoutDashes(data));
        }
        else {
            string data;

            cout << endl << "Podaj date (yyyy-mm-dd): ";
            data = AuxiliaryMethods::loadLine();

            while (true) {
                if (AuxiliaryMethods::checkIfDateIsCorrect(data)) {
                    income.setData(AuxiliaryMethods::convertStringDataToIntWithoutDashes(data));
                    break;
                }
                else {
                    cout << "Wprowadzona data jest nieprawidlowa. Wprowadz date ponownie (yyyy-mm-dd): ";
                    data = AuxiliaryMethods::loadLine();
                }
            }
        }

    cout << endl << "Podaj zrodlo przychodu: ";
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
    if (/*fileWithIncomes.addIncomeToFile(income)*/1)
        cout << endl << "Nowy przychod zostal dodany" << endl;
    else
        cout << endl << "Blad. Nie udalo sie dodac nowego adresata do pliku." << endl;
    cout << income.getAmountId() << income.getUserId() << income.getData() << income.getItem() << income.getValue() << endl;
    system("pause");
}

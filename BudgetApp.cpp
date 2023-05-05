#include "BudgetApp.h"

void BudgetApp::registerUser() {
    userManager.registerUser();
}

void BudgetApp::logInUser() {
    userManager.logInUser();
    if (checkIfUserIsLoggedIn()) {
        transactionManager = new TransactionManager(userManager.getLoggedInUserId(), FILE_NAME_WITH_INCOMES, FILE_NAME_WITH_EXPENSES);
    }
}

void BudgetApp::changeLoggedInUserPassword() {
    userManager.changeLoggedInUserPassword();
}

void BudgetApp::logOutUser() {
    userManager.logOutUser();
    delete transactionManager;
    transactionManager = NULL;
}

void BudgetApp::addIncome() {
    transactionManager->addIncome();
}

void BudgetApp::addExpense() {
    transactionManager->addExpense();
}

void BudgetApp::showCurrentMonthBalance() {
    transactionManager->showCurrentMonthBalance();
}

void BudgetApp::showLastMonthBalance() {
    transactionManager->showLastMonthBalance();
}

void BudgetApp::showSelectedPeriodBalance() {
    transactionManager->showSelectedPeriodBalance();
}

void BudgetApp::selectOptionFromMainMenu() {
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "8. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";

    choice = AuxiliaryMethods::loadChar();

    switch (choice)
    {
    case '1':
        registerUser();
        break;
    case '2':
        logInUser();
        break;
    case '8':
        exit(0);
        break;
    default:
        cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
        system("pause");
        break;
    }
}

void BudgetApp::selectOptionFromUserMenu() {
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";

    choice = AuxiliaryMethods::loadChar();

    switch (choice)
    {
    case '1':
        addIncome();
        break;
    case '2':
        addExpense();
        break;
    case '3':
        showCurrentMonthBalance();
        break;
    case '4':
        showLastMonthBalance();
        break;
    case '5':
        showSelectedPeriodBalance();
        break;
    case '6':
        changeLoggedInUserPassword();
        break;
    case '7':
        logOutUser();
        break;
    }
}

bool BudgetApp::checkIfUserIsLoggedIn() {
    return userManager.checkIfUserIsLoggedIn();
}

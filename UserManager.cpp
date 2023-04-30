#include "UserManager.h"

int UserManager::getNewUserId()
{
    if (users.empty())
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::ifLoginExist(string login) {
    for (auto& v : users) {
        if (v.getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

User UserManager::getNewUserData() {
    User user;

    user.setId(getNewUserId());

    cout << "Podaj imie: ";
    user.setName(AuxiliaryMethods::loadLine());

    cout << "Podaj nazwisko: ";
    user.setSurname(AuxiliaryMethods::loadLine());

    do {
        cout << "Podaj login: ";
        user.setLogin(AuxiliaryMethods::loadLine());
    } while (ifLoginExist(user.getLogin()));

    cout << "Podaj haslo: ";
    user.setPassword(AuxiliaryMethods::loadLine());

    return user;
}

void UserManager::registerUser() {
    User user = getNewUserData();

    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

void UserManager::logInUser() {
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = AuxiliaryMethods::loadLine();

    for (auto& v : users) {
        if (v.getLogin() == login) {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--) {

                cout << "Podaj haslo. Pozostalo prob: " << numberOfAttempts << ": ";
                password = AuxiliaryMethods::loadLine();

                if (v.getPassword() == password)
                {
                    loggedInUserId = v.getId();
                    cout << endl << "Zalogowales sie." << endl << endl;

                    system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    loggedInUserId = 0;
    return;
}

void UserManager::changeLoggedInUserPassword() {
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = AuxiliaryMethods::loadLine();

    for (auto& v : users) {
        if (v.getId() == loggedInUserId) {
            v.setPassword(newPassword);
            fileWithUsers.saveChangedUserPasswordToFile(v);

            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
            return;
        }
    }
}

bool UserManager::checkIfUserIsLoggedIn() {
    if (loggedInUserId > 0)
        return true;
    else
        return false;
}

void UserManager::logOutUser() {
    loggedInUserId = 0;
}

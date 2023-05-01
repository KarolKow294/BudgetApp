#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>

#include "User.h"
#include "FileWithUsers.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserManager {
    int loggedInUserId;
    vector <User> users;
    FileWithUsers fileWithUsers;

    User getNewUserData();
    int getNewUserId();
    bool ifLoginExist(string login);

public:
    UserManager(string fileNameWithUsers) : fileWithUsers(fileNameWithUsers)
    {
        loggedInUserId = 0;
        users = fileWithUsers.loadUsersFromFile();
    };

    void registerUser();
    void logInUser();
    void changeLoggedInUserPassword();
    bool checkIfUserIsLoggedIn();
    void logOutUser();
    int getLoggedInUserId();
};

#endif

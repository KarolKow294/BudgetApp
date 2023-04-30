#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>

#include "XmlFile.h"
#include "User.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithUsers : public XmlFile {
    User getUserData();

public:
    FileWithUsers(string fileNameWithUsers) : XmlFile(fileNameWithUsers) {};
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    void saveChangedUserPasswordToFile(User user);
};

#endif

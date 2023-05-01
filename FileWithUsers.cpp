#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user) {
    bool fileExists = xml.Load(FILE_NAME);

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("Id", user.getId());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());

    if (!xml.Save(FILE_NAME)) {
        cout << "Nie udalo sie zapisac danych w pliku " << FILE_NAME << endl;
        system("pause");
    }
}

User FileWithUsers::getUserData() {
    User user;

    xml.IntoElem();
    xml.FindElem("Id");
    user.setId(atoi(MCD_2PCSZ(xml.GetData())));
    xml.FindElem("Name");
    user.setName(MCD_2PCSZ(xml.GetData()));
    xml.FindElem("Surname");
    user.setSurname(MCD_2PCSZ(xml.GetData()));
    xml.FindElem("Login");
    user.setLogin(MCD_2PCSZ(xml.GetData()));
    xml.FindElem("Password");
    user.setPassword(MCD_2PCSZ(xml.GetData()));
    xml.OutOfElem();

    return user;
}

vector <User> FileWithUsers::loadUsersFromFile() {
    User user;
    vector <User> users;

    bool fileExists = xml.Load(FILE_NAME);

    if (fileExists) {
        xml.FindElem();
        xml.IntoElem();

        while (xml.FindElem("User")) {
            user = getUserData();
            users.push_back(user);
        }
    }
    return users;
}

void FileWithUsers::saveChangedUserPasswordToFile(User user) {
    bool fileExists = xml.Load(FILE_NAME);

    if (fileExists) {
        xml.FindElem();
        xml.IntoElem();

        while (xml.FindElem("User")) {
            xml.FindChildElem("Id");
            if (xml.GetChildData() == AuxiliaryMethods::convertIntToString(user.getId() )) {
                xml.IntoElem();
                xml.FindElem("Password");
                xml.RemoveElem();
                xml.AddElem("Password", user.getPassword());

                if (!xml.Save(FILE_NAME)) {
                    cout << "Nie udalo sie zapisac danych w pliku " << FILE_NAME << endl;
                    system("pause");
                }
                return;
            }
        }
    }
}

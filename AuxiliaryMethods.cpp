#include "AuxiliaryMethods.h"

string AuxiliaryMethods::loadLine() {
    string input = "";
    cin.sync();
    getline(cin, input);
    return input;
}

char AuxiliaryMethods::loadChar() {
    string input = "";
    char character  = {0};

    while (true)
    {
        cin.sync();
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}

int AuxiliaryMethods::loadInteger() {
    string input = "";
    int number = 0;

    while (true)
    {
        cin.sync();
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}

double AuxiliaryMethods::loadFloatNumber() {
    string input = "";
    double number = 0;

    while (true)
    {
        cin.sync();
        getline(cin, input);

        if (number = atof(input.c_str()))
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}

string AuxiliaryMethods::convertIntToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int AuxiliaryMethods::convertStringToInt(string word)
{
    int intNumber;
    istringstream iss(word);
    iss >> intNumber;

    return intNumber;
}

string AuxiliaryMethods::getCurrentData() {
    stringstream data;

    const auto& givemetime = chrono::system_clock::to_time_t(chrono::system_clock::now());
    data << put_time(localtime(&givemetime), "%Y-%m-%d");

    return data.str();
}

int AuxiliaryMethods::convertStringDataToIntWithoutDashes(string data) {
    for (int i = 0; i < (int)data.length(); i++) {
        if (data[i] == '-') {
            data.erase(i, 1);
            i --;
        }
    }
    return convertStringToInt(data);
}

/*int AuxiliaryMethods::specifyNumberOfDaysInMotnh(int month) {
    int numberOfDaysInTheCurrentMonth = 0;

    if (month == 4 || month == 6 || month == 9 || month == 11)
        numberOfDaysInTheCurrentMonth = 30;

    else if (month == 2) {
        bool leapyear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

        if (leapyear == 0)
            numberOfDaysInTheCurrentMonth = 28;
        else
            numberOfDaysInTheCurrentMonth = 29;
    }
    else
        numberOfDaysInTheCurrentMonth = 31;

    return numberOfDaysInTheCurrentMonth;
}*/

bool AuxiliaryMethods::checkIfDateIsCorrect(string data) {
    int year = convertStringToInt(data.substr(0, 4));
    int month = convertStringToInt(data.substr(5, 2));
    int day = convertStringToInt(data.substr(8, 2));

    string currentData = getCurrentData();
    int currentYear = convertStringToInt(currentData.substr(0, 4));
    int currentMonth = convertStringToInt(currentData.substr(5, 2));
    //int maxDayInCurrentMotnh = specifyNumberOfDaysInMotnh(currentMonth);

    if (year < 2000 || year > currentYear)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;

    if (month == 2) {
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

        if (isLeapYear) {
            if (day > 29)
                return false;
        }
        else {
            if (day > 28)
                return false;
        }
    }

    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30)
            return false;
    }

    if (year == currentYear && month > currentMonth)
        return false;

    return true;
}

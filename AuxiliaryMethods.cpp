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

        if ( (number = atof(input.c_str())) )
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

string AuxiliaryMethods::convertFloatToString(double number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::getCurrentDate() {
    stringstream date;

    const auto& givemetime = chrono::system_clock::to_time_t(chrono::system_clock::now());
    date << put_time(localtime(&givemetime), "%Y-%m-%d");

    return date.str();
}

int AuxiliaryMethods::convertStringDateToIntWithoutDashes(string date) {
    for (int i = 0; i < (int)date.length(); i++) {
        if (date[i] == '-') {
            date.erase(i, 1);
            i --;
        }
    }
    return convertStringToInt(date);
}

string AuxiliaryMethods::convertIntDateToStringWithDashes(int date) {
    string stringDate = convertIntToString(date);

    stringDate = stringDate.insert(4, "-");
    stringDate = stringDate.insert(7, "-");

    return stringDate;
}

int AuxiliaryMethods::specifyNumberOfDaysInMonth(int year, int month) {
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
}

bool AuxiliaryMethods::checkIfDateIsCorrect(string date) {
    if (!isdigit(date[0]) || date[4] != '-' || date[7] != '-')
        return false;

    int year = convertStringToInt(date.substr(0, 4));
    int month = convertStringToInt(date.substr(5, 2));
    int day = convertStringToInt(date.substr(8, 2));

    string currentDate = getCurrentDate();
    int currentYear = convertStringToInt(currentDate.substr(0, 4));
    int currentMonth = convertStringToInt(currentDate.substr(5, 2));

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

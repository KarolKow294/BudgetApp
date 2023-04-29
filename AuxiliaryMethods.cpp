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

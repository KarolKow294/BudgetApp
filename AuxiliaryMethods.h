#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
#include <chrono>

using namespace std;

class AuxiliaryMethods
{
public:
    static string loadLine();
    static char loadChar();
    static int loadInteger();
    static double loadFloatNumber();
    static string convertIntToString(int number);
    static int convertStringToInt(string word);
    static string getCurrentData();
    static int convertStringDataToIntWithoutDashes(string data);
    static int specifyNumberOfDaysInMotnh(int month);
    static bool checkIfDateIsCorrect(string data);
};

#endif

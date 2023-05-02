#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>

#include "XmlFile.h"
#include "Income.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithIncomes : public XmlFile {
    int lastIncomeId;

    Income getIncomeData();

public:
    FileWithIncomes(string fileNameWithUsers) : XmlFile(fileNameWithUsers) {
        lastIncomeId = 0;
    };

    int getLastIncomeId();
    bool addIncomeToFile(Income income);
    vector <Income> loadLoggedUserIncomesFromFile(int idOfLoggedInUser);
};

#endif

#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>

#include "XmlFile.h"
#include "Expense.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithExpenses : public XmlFile {

public:
    FileWithExpenses(string fileNameWithUsers) : XmlFile(fileNameWithUsers) {};
};

#endif

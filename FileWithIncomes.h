#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>

#include "XmlFile.h"
#include "Income.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithIncomes : public XmlFile {

public:
    FileWithIncomes(string fileNameWithUsers) : XmlFile(fileNameWithUsers) {};
};

#endif

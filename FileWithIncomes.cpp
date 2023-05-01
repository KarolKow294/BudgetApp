#include "FileWithIncomes.h"

int FileWithIncomes::getLastIncomeId() {
    return lastIncomeId;
}

bool FileWithIncomes::addIncomeToFile(Income income) {
    bool fileExists = xml.Load(FILE_NAME);
    string date = AuxiliaryMethods::convertIntDateToStringWithDashes(income.getDate());

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", income.getAmountId());
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("Date", date);
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Value", AuxiliaryMethods::convertFloatToString(income.getValue()));

    if (!xml.Save(FILE_NAME)) {
        return false;
    }
    lastIncomeId++;
    return true;
}

Income FileWithIncomes::getIncomeData() {
    Income income;

    xml.IntoElem();
    xml.ResetMainPos();
    xml.FindElem("IncomeId");
    income.setAmountId(atoi(MCD_2PCSZ(xml.GetData())));
    xml.FindElem("UserId");
    income.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
    xml.FindElem("Date");
    income.setDate(AuxiliaryMethods::convertStringDateToIntWithoutDashes(MCD_2PCSZ(xml.GetData())));
    xml.FindElem("Item");
    income.setItem(MCD_2PCSZ(xml.GetData()));
    xml.FindElem("Value");
    income.setValue(atof(MCD_2PCSZ(xml.GetData())));
    xml.OutOfElem();

    return income;
}

vector <Income> FileWithIncomes::loadLoggedUserIncomesFromFile(int idOfLoggedInUser) {
    Income income;
    vector <Income> incomes;

    bool fileExists = xml.Load(FILE_NAME);

    if (fileExists) {
        xml.FindElem();
        xml.IntoElem();

        while (xml.FindElem("Income")) {
            xml.FindChildElem("UserId");
            if (xml.GetChildData() == AuxiliaryMethods::convertIntToString(idOfLoggedInUser)) {
                income = getIncomeData();
                incomes.push_back(income);
                lastIncomeId = income.getAmountId();
            }
        }
        //test
        for (auto& v : incomes) {
            cout << v.getAmountId() << v.getUserId() << v.getDate() << v.getItem() << v.getValue() << endl;
        }
        system("pause");
    }
    return incomes;
}

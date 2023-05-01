#include <iostream>
#include <windows.h>
#include <winbase.h>
#include <time.h>

#include "BudgetApp.h"

using namespace std;

class Date {
        int year;
        int month;
        int day;

    public:
        Date(int y, int m, int d) {
            year = y;
            month = m;
            day = d;
        }
    getYear() {
        return year;
    }
    getMonth() {
        return month;
    }
    getDay() {
        return day;
    }
    };

bool checkIfTheFirstDateIsOlder(Date firstDate, Date secondDate) {
    if (firstDate.getYear() < secondDate.getYear())
        return true;
    if (firstDate.getYear() == secondDate.getYear() && firstDate.getMonth() < secondDate.getMonth())
        return true;
    if (firstDate.getYear() == secondDate.getYear() && firstDate.getMonth() == secondDate.getMonth() &&
                              firstDate.getDay() < secondDate.getDay())
        return true;

    return false;
}

int main()
{
    BudgetApp budgetApp("Users.xml", "Incomes.xml", "Expenses.xml");

    while (true)
    {
        if (!budgetApp.checkIfUserIsLoggedIn())
        {
            budgetApp.selectOptionFromMainMenu();
        }
        else
        {
            budgetApp.selectOptionFromUserMenu();
        }
    }

    /*//pobranie aktualnej daty
    int year, month, day;

    SYSTEMTIME st;
    GetSystemTime(&st);
    year = st.wYear;
    month = st.wMonth;
    day = st.wDay;

    if (month > 9)
        cout << year << "-" << month << "-" << day << endl;
    else
        cout << year << "-0" << month << "-" << day << endl;

    //alternatywa dla aktualnej daty
    int year2, month2, day2;

    time_t t = time(0);
    tm* now = localtime(&t);
    year2 = (now->tm_year + 1900);
    month2 = (now->tm_mon + 1);
    day2 = now->tm_mday;

    if (month2 > 9)
        cout << year2 << "-" << month2 << "-" << day2 << endl;
    else
        cout << year2 << "-0" << month2 << "-" << day2 << endl;


    //ile dni ma aktualny miesiac z uwzglednieniem roku przestepnego
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

    cout << endl << numberOfDaysInTheCurrentMonth << endl;

    //porównanie dat

    Date firstDate(1992, 5, 11);
    Date secondDate(2012, 11, 5);

    if (checkIfTheFirstDateIsOlder(firstDate, secondDate))
        cout << "Tak, pierwsza data jest starsza" << endl;
    else if (!checkIfTheFirstDateIsOlder(firstDate, secondDate))
        cout << "Nie, pierwsza data nie jest starsza" << endl;



    CMarkup xml;

    bool fileExists = xml.Load( "users.xml" );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", "1");
    xml.AddElem("Login", "karol");
    xml.AddElem("Password", "789");

    xml.Save("users.xml");

    bool fileExists = xml.Load( "incomes.xml" );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.FindElem("Date");
    xml.IntoElem();

    xml.FindElem("Year");
    int year1 = atoi(MCD_2PCSZ(xml.GetData()));
    xml.FindElem("Month");
    int month1 = atoi(MCD_2PCSZ(xml.GetData()));
    xml.FindElem("Day");
    int day1 = atoi(MCD_2PCSZ(xml.GetData()));

    cout << year1 << "-" << month1 << "-" << day1;

    xml.AddElem("Year", year);
    xml.AddElem("Month", month);
    xml.AddElem("Day", day);
    xml.OutOfElem();

    xml.AddElem("What_the_income_is_about");
    xml.IntoElem();
    xml.AddElem("Source", "payment");
    xml.OutOfElem();

    xml.AddElem("Revenue_value");
    xml.IntoElem();
    xml.AddElem("Value", "1500");

    xml.Save("incomes.xml");*/

    return 0;
}

#include <iostream>
using namespace std;
int main(void) {
    int year, month, day;
    cout << "Input year(it must be more then 0): ";
    cin >> year;
    cout << "Input month(it must be from 1 to 12): ";
    cin >> month;
    cout << "Input day(it must be from 1 to 31-28(it depends)): ";
    cin >> day;
    if((year < 1900) || (month > 12) || (month < 1) || (day > 31) || (day < 1))
    {
        cout << "One of the values is wrong";
        return 1;
    }
    month -= 2;
    if(month <= 0) {
        month += 12;
        year -= 1;
    }
    month = month * 83 / 32;
    month += day;
    month += year;
    month += year / 4;
    month -= (year / 100);
    month += (year / 400);
    cout << month % 7;
    return 0;
    }

#include <iostream>
using namespace std;
int main(void) { 
    int year;
    cout << "Enter a year: ";
    cin >> year;
    if (year % 4 != 0)
        cout << "common year" << endl;
    else if (year % 100 != 0)
        cout << "leap year" << endl;
    else if (year % 400 != 0)
        cout << "common year" << endl;
    else
        cout << "leap year" << endl;
    return 0;
}
#include <iostream>
using namespace std;
int main(void) { 
    int year;
    cout << "Enter a year: ";
    cin >> year;
    int a, b, c, d, e;
    a = year % 19;
    b = year % 4;
    c = year % 7;
    d = (a * 19 + 24) % 30;
    e = (2 * b + 4 * c + 6 * d + 5) % 7;
    if (d + e < 10)
        {
            cout << "March "; 
            cout << d + e + 22  << endl;
        }
    else 
        {
            cout << "April ";
            cout << (d + e - 9) << endl;
        }
}
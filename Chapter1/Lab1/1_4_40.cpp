#include <iostream>
using namespace std;
int main(void) {
    float pi = 3.14159265359;
    float x,y;
    cout << "Enter value for x: ";
    cin >> x;
    float sqrx = x * x;
    float sqrpi = pi * pi;
    float first = sqrx / (sqrpi * (sqrx + 0.5));
    float second = 1 + (sqrx / (sqrpi * (sqrx - 0.5) * (sqrx - 0.5)));
    y = first * second;
    cout << "y = " << y;
    return 0;
}
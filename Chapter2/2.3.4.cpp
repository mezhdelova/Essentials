#include <iostream>
using namespace std;
int main(void) {
    int power;
    double result = 1;
    cout << "Input the power of 2 (from 0 to 63): ";
    cin >> power;
    if((power < 0) || (power > 63))
    {
        cout << "Value's wrong";
        return 1;
    }
    for(int i = 0; i < power; i++)
        result /= 2;
    cout.precision(20);
    cout << "2^" << power << " = " << result;
    return 0;
}
#include <iostream>
using namespace std;
int main(void) {
    long n, first = 1, second = 1, save;
    cout << "Input the n-th number Fibonacci number (it must be int, more the 0): ";
    cin >> n;
    if(n <= 0)
    {
        cout << "Value's wrong";
        return 1;
    }
    for (int i = 0; i < n - 2; i++)
    {
        save = second;
        second = first + second;
        first = save;
    }
    cout << second;
    return 0; 
    }
#include <iostream>
using namespace std;
int main(void) {
    int c, steps = 0;//counter for steps in loop
    cout << "Input the int number more then 0: ";
    cin >> c;
    if(c <= 0)
    {
        cout << "Value's wrong";
        return 1;
    }
    while(c != 1)
    {
        if(!(c % 2))
            c /= 2;
        else
            c = c * 3 + 1;
        steps++;
        cout << c << endl;
    }
    cout << "Steps: " << steps;
    return 0;
    }
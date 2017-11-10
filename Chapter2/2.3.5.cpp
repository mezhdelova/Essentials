#include <iostream>
using namespace std;
int main(void) {
    int side;
    cout << "Input the square's side long (it must be int, from 1 to 177): ";
    cin >> side;
    if((side <= 0) || (side > 177))
    {
        cout << "Value's wrong";
        return 1;
    }
    cout << '+';
    for(int i = 0; i < side; i++)
        cout << '-'; 
    cout << '+' << endl;
    for(int i = 0; i < side; i++) 
    {  
        cout << '|';
        for(int j = 0; j < side; j++)
            cout << ' ';
        cout << '|' << endl;
    } 
    cout << '+';
    for(int i = 0; i < side; i++)
        cout << '-';
    cout << '+' << endl;
    return 0; 
    }
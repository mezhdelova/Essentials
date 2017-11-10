#include <iostream>
using namespace std;
int main()
{   
    int value;
    int bitarray[16];
    bool result = true;
    cout << "Input decimal value: ";
    cin >> value;
    cout << "This value in binary: ";
    for(int i = 0; i < 16; i++)
    {
        bitarray[15 - i] = value % 2;
        cout << bitarray[15 - i];
        value /= 2;
    }
    for(int i = 0; i < 16; i++)
    {
        if(bitarray[15 - i] != bitarray[i])
        {
            result = false;
            break;
        }
    }
    if(result)
        cout << " is a bitwise palindrome";
    else
        cout << " isn't a bitwise palindrome";
    return 0;
}
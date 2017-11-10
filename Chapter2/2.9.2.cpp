#include <iostream>
using namespace std;
int main(void) {
    int valute[5] = { 50, 20, 10, 5, 1};
    int value;
    cout << "Input the value: ";
    cin >> value;

    for(int i = 0; i <= 4; i++)
    {
      while(value >= valute[i])
      {
        cout << valute[i] << " ";
        value -= valute[i];
      }
    }
}

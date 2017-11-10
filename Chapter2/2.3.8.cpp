#include <iostream>
using namespace std;
int main(void) {
    int num;
    cout << "Input number: ";
    cin >> num;
    int res = 1;
    if (num == 0)
      res = 1;
    else
    {
      for (int i = 1; i <= num; i++ )
      {
        res *= i;
      }
    }
    cout << res;
}

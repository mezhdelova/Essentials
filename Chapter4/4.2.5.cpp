#include <iostream>
using namespace std;
int main(void) {
    int N;
    cout << "Input N: ";
    cin >> N;
    int sum = 0;
    for (int i = 1; i <= N; i++)
      sum += i;
    cout << sum;    
}

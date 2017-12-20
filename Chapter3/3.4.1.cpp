#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int num) {
if num
}
int main(void) {
for(int i = 0; i <= 21; i++)
if(isPrime(i))
cout << i << " ";
cout << endl;
return 0;
}
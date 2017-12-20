#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int n){
	if(n==1) // чомусь 1 не просте, це жахливий пробєл в моїй освіті
		return false;
	
	for(int d=2; d*d<=n; d++){ 
		// розділилось націло - не просте
		if(n%d==0) 
			return false;
		}
	
	return true;
	}
int main(void) {
for(int i = 0; i <= 21; i++)
if(isPrime(i))
cout << i << " ";
cout << endl;
return 0;
}

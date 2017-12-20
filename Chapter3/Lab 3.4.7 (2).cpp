#include <iostream>
using namespace std;
bool isLeap(int year) {
	if (year % 4 != 0 && year % 400 != 0)
		return false;
	else return true;
}
int monthLength(int year, int month) {
	int vector[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 };
		if (isLeap(year)==true)
		{
			vector[1] = 29;
		}
		return vector[month - 1];
}
int main(void) {
	for (int yr = 2000; yr < 2002; yr++) {
		for (int mo = 1; mo <= 12; mo++)
			cout << monthLength(yr, mo) << " ";
		cout << endl;
	}
	return 0;
}

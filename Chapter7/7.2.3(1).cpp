#include <string>
#include <iostream>

using namespace std;
const int DivideByZero = 111;

float internaldiv(float arg1, float arg2)
{
	if (0 == arg2)
		throw DivideByZero;
	return arg1 / arg2;
}
float div(float arg1, float arg2) {
	if (arg2 == 0.0)
		throw string ("Your input is not valid. You can't divide by zero.");
	
	return internaldiv(arg1, arg2);
}
int main(void) {
	float  a, b;
	try
	{
		while (cin >> a) {
			cin >> b;
			cout  << div(a, b) << endl;
		}
				
	}
	catch (string &exp)
	{
		cout << "Are you kidding me?" << endl;
		cout << exp << endl;
	}
			
	
	return 0;
}
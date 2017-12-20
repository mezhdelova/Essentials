#include <iostream>
using namespace std;
//add your own exception class here
//add functions code here

float rectangle_area(float a, float b)
{
    return a*b;
}
float square_area(float a)
{
    return a*a;
    
}
int main(void) {
double a, b;
cin >> a;
cin >> b;
try
{
double rsquare = square_area(a);
double rrectangle = rectangle_area(a,b);
if(a > 0 && b > 0)
{
cout << rsquare << endl << rrectangle << endl;
}
else (throw 123);
}
catch(int e)
{
    cout << "An exception occurred. Maybe you've input wrong number" ;
}

//add a suitable catch block here
return 0;
}

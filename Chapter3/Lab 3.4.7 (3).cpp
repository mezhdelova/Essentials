#include <iostream>
using namespace std;
struct Date {
int year;
int month;
int day;
};
bool isLeap(int year) {
 return year%4==0;
}
int monthLength(int year, int month) {
    if(!isLeap(year)&&month==2)
        return 28;
    else
        return 28+(month+month/8)%2+2%month+2/month;
}
int dayOfYear(Date date) {
int numberOfDays = 0;
for (int i=1;i<date.month;i++)
{

        numberOfDays+=monthLength(date.year,i);

}
return     numberOfDays+=date.day;

}
int main(void) {
Date d;
cout << "Enter year month day: "<<endl;

cin >> d.year >> d.month >> d.day;
cout << dayOfYear(d) << endl;

return 0;
}

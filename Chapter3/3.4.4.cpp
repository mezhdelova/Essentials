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

int daysBetween(Date since, Date till){
if (since.year > till.year|| since.year <= till.year && since.month > till.month || since.year <= till.year && since.month <= till.month && since.day > till.day)
return -1;
else{
    if (since.year ==  till.year && since.month == till.month)
        return till.day - since.day;
    else 
      {
        if(since.year == till.year)  
         {return dayOfYear(till) - dayOfYear(since);}
        else
          {
            int dayst = dayOfYear(till);
   int dayss;
   if(since.year != till.year){
  if(isLeap(since.year))
   {dayss = 366 - dayOfYear(since);}
   else  {dayss = 365 - dayOfYear(since);}
   }
   else dayss = dayOfYear(since);
   int daysBetYears = 0;
   for (int year = since.year + 1; year < till.year;  year++)
   {
       int daysInYear;
       Date d;
       d.day = 31,d.month = 12, d.year = year;
       
       daysInYear = dayOfYear(d);
       daysBetYears+=daysInYear;
   }
   return dayst+dayss+daysBetYears;
                    
          }  
      }
  }
}
int main(void){
Date since;
Date till;
cout << "Enter year month day since: "<<endl;
cin >> since.year >> since.month >> since.day;
cout << "Enter year month day till: "<<endl;
cin >> till.year >> till.month >> till.day;
cout << daysBetween(since, till) << endl;
return 0;
}
  
  
  



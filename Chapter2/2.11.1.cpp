#include <iostream>
using namespace std;
struct Time
{
  int hour;
  int minute;
};
int main(void) {
    Time myTime;
    int min;
    cout << "Input hour: ";
    cin >> myTime.hour;
    cout << "Input minute: ";
    cin >> myTime.minute;
    if(myTime.hour > 23 || myTime.hour < 0 || myTime.minute > 60
      || myTime.minute < 0)
      cout << "Wrong time!";
    else
      {
        cout << "Input minute: ";
        cin >> min;
        myTime.minute += min;
        while ( myTime.minute >= 60 )
        {
          myTime.hour++;
          if(myTime.hour > 23)
            myTime.hour -= 24;
          myTime.minute -= 60;
        }
        cout << myTime.hour << ":" << myTime.minute;
      }
}

#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
string name;
int age;
string status;
};
void print(Person* person)
{
cout << person->name << " is " << person->age << " years old and he/she is " << person->status << endl;
}
void checkMaritalStatus(Person* person)
{
 if(person->status == "married")
    cout << person->name << " is " <<  person->status << " and he/she is very happy!" << endl;
  else  if(person->status == "single")
    cout << person->name << " is " <<  person->status << " but someday will find his/her true love" << endl;
    else  if(person->status == "attached")
    cout << person->name << " is " <<  person->status << "  he/she has a friend" << endl;
    else cout << person->name << "  not prefer to say his/her marital status" << endl;
}
int main()
{
Person person;
cout << "Enter person name" << endl;;
getline(cin, person.name);
cout << "Enter person age" << endl;
cin >> person.age;
cout << "Enter person status (married, single, attached, not prefer to say status)" << endl;
cin >> person.status;
cout << "Meet " << person.name<< endl;
print(&person);
checkMaritalStatus(&person);
return 0;
}

#include <iostream>
//#include <conio.h>
#include <math.h>
 
using namespace std;

#include <iostream>
#include <string>
using namespace std;
class Square
{
public:
Square(double side);
void MyTrustedFriend(Square sqr);
void print(Square* sqr);
private:
double side;
double area;
};
Square::Square(double side)
{
this->side = side;
this->area = side * side;
}
 void Square::MyTrustedFriend(Square sqr)
{  
    print(&sqr);
}
void Square::print(Square* square)
{
cout << "Square: side=" << square->side << " area=" << square->area << endl;
}
double Set_side(void)
{ int side;
  cout << "Input side";
  cin >> side;
  if(side > 0)
  return side;
  else return 0;
}
int main()
{
    Square s(Set_side());
    s.MyTrustedFriend(s);
   return 0;
}

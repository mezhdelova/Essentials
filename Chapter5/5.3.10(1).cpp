#include <iostream>
class FlightBooking {
public:
FlightBooking(int id, int capacity, int reserved);
void printStatus();
private:
int id;
int capacity;
int reserved;
};
void FlightBooking::printStatus()
{
    
    double resperc = this->reserved;
     double capperc = this->capacity;
 std::cout<<"Fligth  "<<this->id<<" : "<<this->capacity<<"/" <<this->reserved<<" (" << (resperc/capperc)*100 << "%) seats reserved" <<std::endl;
}
FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
 this->id = id;
 this->capacity = capacity;
 this->reserved = reserved;
}
int main() {
int reserved = 0,
capacity = 0;
std::cout << "Provide flight capacity: ";
std::cin >> capacity;
std::cout << "Provide number of reserved seats: ";
std::cin >> reserved;
FlightBooking booking(1, capacity, reserved);
booking.printStatus();
return 0;
}

#include <iostream>
using namespace std;
int main(void) {
    float grossprice, taxrate, netprice, taxvalue;
    cout << "Enter a gross price(it must be > 0): ";
    cin >> grossprice;
    while(grossprice < 0)
    {
        cout << "The value's wrong.It must be > 0.Please enter one more time" << endl;
        cin >> grossprice;
    }
    cout << "Enter a tax rate in %(it must be > 0 and < 100) :";
    cin >> taxrate;
    while((taxrate < 0) || (taxrate > 100))
    {
        cout << "The value's wrong.It must be > 0 and < 100.Please enter one more time" << endl;
        cin >> taxrate;
    }
    netprice = grossprice / (1 + taxrate / 100);
    taxvalue = grossprice - netprice;
    
    cout << "Net price: " << netprice << endl;
    cout << "Tax value: " << taxvalue << endl;
    return 0;
    }
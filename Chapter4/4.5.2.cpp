#include <iostream>
#include <string>
using namespace std;

int main()
{
    string text;
    std::getline (std::cin,text);
    string from;
    std::getline (std::cin,from);
    string to;
    std::getline (std::cin,to);
       int pos = text.find(from);
while (pos != -1) {
text.replace(pos, from.size(), to);
pos = text.find(from);
}
    cout << text << endl;

    return 0;
}

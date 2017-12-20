#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Input original text";
    string text;
    getline (cin,text);
      cout << "Input the word you want to replace";
    string from;
    getline (cin,from);
    cout << "Input the wrod you want to replace with";
    string to;
    getline (cin,to);
       int pos = text.find(from); 
while (pos != -1) { 
text.replace(pos, from.size(), to); 
pos = text.find(from); 
}


    cout << text << endl;

    return 0;
}
#include <iostream>
#include <string>
using namespace std;
int main()
{
  string text;
  cout <<  "Input sentence"<<endl;
  cin >> text;
 cout << "Input the word you want to replace"<<endl;
 string from;
  cin >> from;
  cout << "Input the word you want to replace with";
  string to;
  cin >> to;

  cout << "Sentence was like: \t" << text << endl;
  text.replace(text.find(from),from.length(),to);
  cout << "With replacement: \t" << text << endl << endl;
  return 0;
}

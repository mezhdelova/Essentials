#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool is_anagram(std::string s1, std::string s2)
{
  std::sort(s1.begin(), s1.end());
  std::sort(s2.begin(), s2.end());
  return s1 == s2;
}
int main(void) {
    string s1,s2;
    cout<< "Input 2 words and we will check either it an anagrams or not..."<<endl;
    getline(cin,s1);
    getline(cin,s2);
    cout<<(is_anagram(s1,s2)?"amagrams":"not anagrams")<<endl;

	return 0;
}

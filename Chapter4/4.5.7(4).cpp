#include <iostream>
#include <string>
bool anagram(std::string a, std::string b) {
    int a_sum = 0, b_sum = 0, i = 0;
    while (a[i] != '\0') {
        a_sum += (int)a[i];
        b_sum += (int)b[i];
        i++;
    }
    return a_sum == b_sum;
}
int main()
{
  std::string a;
  std::cout <<"input first string"<< "!\n";
  getline (std::cin, a);
  std::cout <<"input second string"<< "!\n";
  std::string b;
  getline (std::cin,b);
  if(anagram(a,b))
  std::cout <<"this is anagram"<< "!\n";
  else 
  std::cout <<"this is not anagram"<< "!\n";
}

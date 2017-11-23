#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
std::string removeWhitespaces(std::string input)
{
    bool prev_is_space = true;
    input.erase(std::remove_if(input.begin(), input.end(),
    [&prev_is_space](char curr) {
        bool r = std::isspace(curr) && prev_is_space;
        prev_is_space = std::isspace(curr);
        return r;}), input.end());
    return input;
}
int main()
{
  std::string sentence, word;
  std::getline(std::cin, sentence);
  sentence = removeWhitespaces(sentence);
  sentence += ' ';
  int spacePos, nextSpace, count, found;
  for (int i = 0; i < sentence.length(); i++)
  {
      spacePos = -1;
      nextSpace = 0;
      while (nextSpace <= sentence.find_last_of(" "))
      {
        nextSpace = sentence.find(" ", spacePos + 1);
        if (nextSpace != std::string::npos)
          {
            count = nextSpace - spacePos - 1;
            word = sentence.substr(spacePos + 1, count) + ' ';
            found = sentence.find(word, spacePos + 2);
            if ((found != std::string::npos) & (found == nextSpace + 1))
              sentence.erase(nextSpace + 1, count + 1);
          }
          spacePos = nextSpace;
      }
  }
  std::cout << sentence << "\n";
}

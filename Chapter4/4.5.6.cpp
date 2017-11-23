#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
void removespaces(std::string input)
{

    bool prev = true;
    input.erase(std::remove_if(input.begin(), input.end(),
    [&prev](char curr) {
        bool r = std::isspace(curr) && prev;
        prev = std::isspace(curr);
        return r;}), input.end());
        std::cout << input << "\n";
}
int main()
{
    std::cout << "Input sentence for delete extra whitespaces"<< std::endl;
    std::string input;
    std::getline(std::cin, input);
    removespaces(input);
}

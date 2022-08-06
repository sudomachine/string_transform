#include <iostream>
#include <string>
#include <map>

void encrypt(std::string input_string);

void transformChar(char& input_symbol, bool is_forward);

template <typename T>
void print(T variable);

int main()
{
    std::map<char, bool>

    char let = 'a';
    print<char>(let);

    transformChar(let, true);
    print<char>(let);
    return 0;
}

void encrypt(std::string str)
{

}

void transformChar(char& symbol, bool is_forward)
{
    if (is_forward)
        symbol = '(';
    else
        symbol = ')';
}

template <typename T>
void print(T var)
{
    std::cout << var << std::endl;
}

#include <iostream>
#include <string>
#include <map>

/**
 * @brief encrypt input string data from char to forward or backward parenthesis '(' or ')'
 * @param input_string
 */
void encrypt(std::string& input_string);

/**
 * @brief isFirstEntry function checks for the presence of the char in the chars array
 * and transfrom char from uppercase to lowercase
 * @param input_char
 * @param chars_array
 * @return true if char presents if the array or false otherwise
 */
bool isFirstEntry(char& input_char, std::map<char, bool>& chars_array);

/**
 * @brief transformChar function transfroms input char to forward or backward parenthesis '(' or ')'
 * @param input_symbol
 * @param is_forward is a flag that transforms to forward parenthesis ')' if true
 * or backward parenthesis ')' if false
 */
void transformChar(char& input_symbol, bool is_forward);

/**
 * @brief uppercaseCharToLowercaseChar function transfrom char from uppercase to lowercase
 * @param input_char
 */
void uppercaseCharToLowercaseChar(char& input_char);

/**
 * @brief template print function for any simple type that prints input variable to screen
 * @param variable for screen printing
 */
template <typename T>
void print(T variable);

/**
 * @brief template specialization of print function for map<char, bool> only
 * that prints pair of char and bool to the screen: 'char' bool
 * @param std::map<char, bool>
 */
template <>
void print(std::map<char, bool> map);

int main()
{
    // Входные массивы
    const size_t arrays_number = 5;
    std::string arrays[arrays_number] = {
        "Andrey Sudakov Alekseevich",
        "din",
        "recede",
        "Success",
        "(( @"
    };

    // Проведение теста
    for (size_t i = 0; i < arrays_number; ++i)
    {
        print(arrays[i]);
        encrypt(arrays[i]);
        print(arrays[i]);
    }

    return 0;
}

void encrypt(std::string& str)
{
    std::map<char, bool> chars;

    // Заполнение массива chars - первый проход по символам строки
    for (auto& ch: str)
    {
        isFirstEntry(ch, chars);
    }

    // Преобразование символов строки - второй проход по массиву
    for (auto& ch: str)
    {
        /* Преобразовать входной символ. Для этого в функцию передается
         * сам символ по ссылке (чтобы его поменять в функции и вне функции)
         * и флаг, который говорит на какую скобку нужно поменять символ:
         * на прямую '(' (true) или обратную ')' (false).
         * */
        transformChar(ch, chars.find(ch)->second);
    }
}

void uppercaseCharToLowercaseChar(char& ch)
{
    if (ch >= static_cast<char>(65) and ch <= static_cast<char>(90))
    {
        ch = ch + static_cast<char>(32);
    }
}

bool isFirstEntry(char& ch, std::map<char, bool>& chars)
{
    /* Необходимо привести все заглавные буквы к строчному виду.
     * Опираясь на таблицу ASCII, можно определить, что все прописные
     * буквы находится в диапазоне: [65; 90]. И разница между прописной 'А'
     * и строчной 'а' равняется 32 элементам. Получается, что к каждой
     * прописной букве можно добавить 32, тогда получится прописная буква.
     * Осталось выявить это.
     * P.S.: программа рассчитана только на шифрование букв латинского алфавита
     * и остальных символов.
     * */
    uppercaseCharToLowercaseChar(ch);

    /* Итератор, который указывает на пару, соответствующую ключу ch. */
    auto it = chars.find(ch);

    /* Если в массиве нет символа, то нужно добавить его туда с флагом true.
     * true - означает круглую скобку с прямым направлением - для символов,
     * которые встретились один раз.
     * */
    if (it == chars.end())
    {
        chars.insert({ch, true});
        return true; // первое появление символа ch в массиве
    }
    /* А если в массиве уже есть такой символ,
     * то значение этого символа поменять на false.
     * false означает круглую скобку с обратным направлением для символов,
     * которые встретились больше одного раза.
     * */
    else
    {
        // Если флаг не был ранее заменен на false, то нужно это сделать
        if (it->second)
        {
            it->second = false;
        }
        return false; // повторное появление символа ch в массиве
    }
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

template <>
void print(std::map<char, bool> map)
{
    for (auto& pair: map)
    {
        std::cout << "'" << pair.first << "' " << pair.second << std::endl;
    }
}

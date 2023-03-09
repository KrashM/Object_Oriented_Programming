#include <iostream>
#include <cstring>

constexpr int CHAR_DIFF{ 'a' - 'A' };

char toLowerCase(char ch);
char toUpperCase(char ch);

void changeStr(char* str, char (*changer)(char));

int main() {
    constexpr std::size_t STR_CAPACITY{ 1024 };
    char str[STR_CAPACITY + 1];

    std::cin.getline(str, STR_CAPACITY);

    changeStr(str, toUpperCase);
    std::cout << str << std::endl;
    
    changeStr(str, toLowerCase);
    std::cout << str << std::endl;

    return 0;
}

char toLowerCase(char ch) {
    return (ch >= 'A' && ch <= 'Z' ? ch + CHAR_DIFF : ch);
}

char toUpperCase(char ch) {
    return (ch >= 'a' && ch <= 'z' ? ch - CHAR_DIFF : ch);
}

void changeStr(char* str, char (*changer)(char)) {
    const std::size_t SIZE{ strlen(str) };

    for (std::size_t index{ 0 }; index < SIZE; ++index) {
        str[index] = changer(str[index]);
    }
}

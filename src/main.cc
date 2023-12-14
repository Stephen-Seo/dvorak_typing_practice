#include <string>
#include <iostream>

std::string get_next_word() {
    std::string word;
    while (std::cin.good()) {
        int in = std::cin.get();
        if (in != std::char_traits<char>::eof() && in != ' ' && in != '\n' && in != '\r') {
            word.push_back((char)in);
        } else if (in == ' '|| in == '\n' || in == '\r' || in == '\t') {
            break;
        }
    }

    return word;
}

int main() {
    std::string word;

    do {
        word = get_next_word();
        if (!word.empty()) {
            std::cout << word << '\n';
        }
    } while (!std::cin.eof());

    return 0;
}

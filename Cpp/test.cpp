#include <iostream>
#include <cstdio> // C 스타일 IO를 위해 필요

int main() {
    std::cout << "Enter text (CTRL+D to signal EOF): " << std::endl;

    std::string input;
    std::getline(std::cin, input);

    if (std::cin.eof()) 
        std::cout << "EOF detected on std::cin\n"; 
    if (feof(stdin)) 
        std::cout << "EOF detected on stdin\n";

    // std::cin.clear(); // std::cin의 EOF 상태 클리어
	clearerr(stdin);

    std::cout << "\nAfter std::cin.clear(), enter more text: \n" << std::endl;
    std::getline(std::cin, input);

    if (std::cin.eof()) 
        std::cout << "EOF detected on std::cin again\n";

    if (feof(stdin)) 
        std::cout << "EOF detected on stdin again\n";

    return 0;
}
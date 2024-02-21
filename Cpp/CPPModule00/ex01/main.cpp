#include "PhoneBook.hpp"

int main()
{
	PhoneBook   pb;
    std::string cmd;

    while(true){
        std::cout << "Select command in [ADD / SEARCH / EXIT] : ";
        std::getline(std::cin, cmd);
        if (cmd == "EXIT")
            exit(0);
        else if (cmd == "ADD")
            pb.addContact();
        else if (cmd == "SEARCH")
            pb.searchContact();
        else
            std::cout << "Error: Invalid command" << std::endl;
        if (std::cin.eof()) {
			clearerr(stdin);
            std::cin.clear();
        }
    }
    return (0);
}
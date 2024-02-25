#include "PhoneBook.hpp"

int main()
{
	PhoneBook pb;
	std::string str;

	while (true)
	{
		std::cout << "Select command in (ADD , SEARCH , EXIT) : ";
		std::getline(std::cin, str);

		if (str == "EXIT")
			exit(0);
		else if (str == "ADD")
			pb.addContact();
		else if (str == "SEARCH")
			pb.searchContact();
		else
		{
			if (std::cin.eof())
				std::cout << std::endl;
			std::cout << "Error: Invalid command" << std::endl;
		}
		if (std::cin.eof())
		{
			clearerr(stdin);
			std::cin.clear();
		}
	}
	return 0;
}
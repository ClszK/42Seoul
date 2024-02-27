#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "ADDRESS" << std::endl;
	std::cout << "str's address       : " << &str << std::endl;
	std::cout << "stringPTR's address : " << stringPTR << std::endl;
	std::cout << "stringREF's address : " << &stringREF << std::endl;

	std::cout << std::endl << "VALUE" << std::endl;
	std::cout << "str's value         : " << str << std::endl;
	std::cout << "stringPTR's value   : " << *stringPTR << std::endl;
	std::cout << "stringREF's value   : " << stringREF << std::endl;

	return 0;
}
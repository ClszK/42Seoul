#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
	save_contact = 0;
}

PhoneBook::~PhoneBook() {}

std::string getline_valid(const std::string &prompt)
{
	std::string input;

	while (true)
	{
		std::cout << prompt << std::endl;
		std::getline(std::cin, input);

		if (std::cin.eof())
		{
			clearerr(stdin);
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "EOF detected. Please enter valid input." << std::endl;
		}
		else if (input.empty())
			std::cout << "Nothing Input. Retry Input." << std::endl;
		else
			return input;
	}
}

int getInteger(int save_contact)
{
	std::string input;
	int printIndex;

	std::cout << "Enter an integer: ";
	std::getline(std::cin, input);

	std::istringstream stream(input);
	if (stream >> printIndex)
	{
		char remaining;
		if (stream >> remaining)
			std::cout << "That's not a pure integer." << std::endl;
		else if (printIndex < 0 || printIndex >= save_contact)
		{
			std::cout << "Invalid Index." << std::endl;
			return -1;
		}
		else
			return printIndex;
		std::cin.clear();
	}
	else
		std::cout << "That's not an integer." << std::endl;
	return -1;
}

std::string formatText(const std::string &text)
{
	unsigned long maxWidth = 10;
	if (text.length() > maxWidth)
		return text.substr(0, maxWidth - 1) + ".";
	return text;
}

void printColumn(const std::string &str)
{
	std::cout << "|" << std::setw(10) << formatText(str);
}

std::string numberToString(int number)
{
	std::ostringstream sss;
	sss << number;
	return sss.str();
}

void PhoneBook::addContact()
{
	Contact newContact;
	std::string str;

	str = getline_valid("Enter First Name!");
	newContact.setFirstrName(str);

	str = getline_valid("Enter Last Name!");
	newContact.setLastName(str);

	str = getline_valid("Enter Nickname!");
	newContact.setNickname(str);

	str = getline_valid("Enter Phone Number!");
	newContact.setPhoneNumber(str);

	str = getline_valid("Enter Darkest Secret!");
	newContact.setDarkestSecret(str);

	contacts[index] = newContact;
	index = (index + 1) % 8;
	if (save_contact < 8)
		save_contact++;
}

void PhoneBook::searchContact()
{
	int printIndex;

	if (save_contact == 0)
	{
		std::cout << "Contact does not exist" << std::endl;
		return;
	}
	std::cout << std::endl
			  << std::right;
	printColumn("Index");
	printColumn("FirstName");
	printColumn("LastName");
	printColumn("Nickname");
	std::cout << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < save_contact; i++)
	{
		printColumn(numberToString(i));
		printColumn(contacts[i].getFirstName());
		printColumn(contacts[i].getLastName());
		printColumn(contacts[i].getNickName());
		std::cout << std::endl;
	}
	printIndex = getInteger(save_contact);
	if (printIndex < 0)
		return;
	std::cout << "First Name : " << contacts[printIndex].getFirstName() << std::endl;
	std::cout << "Last Name : " << contacts[printIndex].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[printIndex].getNickName() << std::endl;
	std::cout << "Phone Number: " << contacts[printIndex].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[printIndex].getDarkestSecret() << std::endl;
}

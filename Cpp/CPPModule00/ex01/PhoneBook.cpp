#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
	save_contact = 0;
}

PhoneBook::PhoneBook(const PhoneBook &p)
{
	for (int i = 0; i < 8; i++)
		contacts[i] = p.contacts[i];
	index = p.index;
	save_contact = p.save_contact;
}

PhoneBook &PhoneBook::operator=(const PhoneBook &p)
{
	if (this == &p)
		return *this;

	for (int i = 0; i < 8; i++)
		contacts[i] = p.contacts[i];
	index = p.index;
	save_contact = p.save_contact;

	return *this;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact()
{
	Contact		newContact;
	std::string	str;

	index = (index + 1) % 8;
	std::cout << "Enter First Name!" << std::endl;
	std::getline(std::cin, str);
	newContact.setFirstrName(str);

	std::cout << "Enter Last Name!" << std::endl;
	std::getline(std::cin, str);
	newContact.setLastName(str);

	std::cout << "Enter Nickname!" << std::endl;
	std::getline(std::cin, str);
	newContact.setNickname(str);

	std::cout << "Enter Phone Number!" << std::endl;
	std::getline(std::cin, str);
	newContact.setPhoneNumber(str);

	std::cout << "Enter Darkest Secret!" << std::endl;
	std::getline(std::cin, str);
	newContact.setDarkestSecret(str);

	contacts[index] = newContact;
}

std::string formatText(const std::string& text)
{
	int maxWidth = 10;
	if (text.length() > maxWidth)
		return text.substr(0, maxWidth - 1) + ".";
	return text;
}

void	printColumn(const std::string& str)
{
	std::cout << "|" << std::setw(10) << formatText(str);
}

void PhoneBook::searchContact() {
	int printIndex;

	std::cout << std::endl << std::right;
	printColumn("Index");
	printColumn("FirstName");
	printColumn("LastName");
	printColumn("Nickname");
	std::cout << "----------------------------------------" << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 8 ; i++)
	{
		printColumn(std::to_string(i));
		printColumn(contacts[i].getFirstName());
		printColumn(contacts[i].getLastName());
		printColumn(contacts[i].getNickName());
		std::cout << std::endl;
	}
}

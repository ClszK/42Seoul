#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <sstream>
# include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int index;
	int	save_contact;

public:
	PhoneBook();
	~PhoneBook();

	void addContact();
	void searchContact();
};

std::string	getline_valid(const std::string &prompt);
int 		getInteger(int save_contact);
std::string	formatText(const std::string &text);
void		printColumn(const std::string &str);
std::string	numberToString(int number);

#endif
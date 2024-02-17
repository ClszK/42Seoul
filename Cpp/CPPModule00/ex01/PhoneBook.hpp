#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int index;
	int	save_contact;

public:
	PhoneBook();
	PhoneBook(const PhoneBook& p);
	PhoneBook& operator=(const PhoneBook& p);
	~PhoneBook();

	void addContact();
	void searchContact();
};

#endif
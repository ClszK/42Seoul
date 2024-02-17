#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(const Contact &c)
{
	firstrName = c.firstrName;
	lastName = c.lastName;
	nickname = c.nickname;
	phoneNumber = c.phoneNumber;
	darkestSecret = c.darkestSecret;
}

Contact& Contact::operator=(const Contact &c)
{
	if (this == &c) return *this;
	
	firstrName = c.firstrName;
	lastName = c.lastName;
	nickname = c.nickname;
	phoneNumber = c.phoneNumber;
	darkestSecret = c.darkestSecret;
	return *this;
}

Contact::~Contact() {}

std::string Contact::getFirstName() { return firstrName; }
std::string Contact::getLastName() { return lastName; }
std::string Contact::getNickName() { return nickname; }
std::string Contact::getPhoneNumber() { return phoneNumber; }
std::string Contact::getDarkestSecret() { return darkestSecret; }

void Contact::setFirstrName(std::string firstName) { this->firstrName = firstName; }
void Contact::setLastName(std::string lastName) { this->lastName = lastName; }
void Contact::setNickname(std::string nickName) { this->nickname = nickName; }
void Contact::setPhoneNumber(std::string phoneNumber) { this->phoneNumber = phoneNumber; }
void Contact::setDarkestSecret(std::string darkestSecret) { this->darkestSecret = darkestSecret; }
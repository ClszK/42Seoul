#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

std::string Contact::getFirstName() const { return firstrName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getNickName() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getDarkestSecret() const{ return darkestSecret; }

void Contact::setFirstrName(std::string firstName) { this->firstrName = firstName; }
void Contact::setLastName(std::string lastName) { this->lastName = lastName; }
void Contact::setNickname(std::string nickName) { this->nickname = nickName; }
void Contact::setPhoneNumber(std::string phoneNumber) { this->phoneNumber = phoneNumber; }
void Contact::setDarkestSecret(std::string darkestSecret) { this->darkestSecret = darkestSecret; }
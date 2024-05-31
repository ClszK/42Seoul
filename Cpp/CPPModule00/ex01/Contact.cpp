#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

std::string Contact::getFirstName() const { return mFirstrName; }
std::string Contact::getLastName() const { return mLastName; }
std::string Contact::getNickName() const { return mNickname; }
std::string Contact::getPhoneNumber() const { return mPhoneNumber; }
std::string Contact::getDarkestSecret() const{ return mDarkestSecret; }

void Contact::setFirstrName(std::string firstName) { mFirstrName = firstName; }
void Contact::setLastName(std::string lastName) { mLastName = lastName; }
void Contact::setNickname(std::string nickName) { mNickname = nickName; }
void Contact::setPhoneNumber(std::string phoneNumber) { mPhoneNumber = phoneNumber; }
void Contact::setDarkestSecret(std::string darkestSecret) { mDarkestSecret = darkestSecret; }
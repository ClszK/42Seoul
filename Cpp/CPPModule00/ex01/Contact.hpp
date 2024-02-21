#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
private:
	std::string firstrName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	Contact();
	~Contact();

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickName() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;

	void setFirstrName(std::string firstName);
	void setLastName(std::string lastName);
	void setNickname(std::string nickName);
	void setPhoneNumber(std::string phoneNumber);
	void setDarkestSecret(std::string darkestSecret);
};

#endif
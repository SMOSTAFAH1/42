#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _count(0), _index(0) {}

PhoneBook::~PhoneBook(void) {}

static size_t	displayLen(const std::string &str) {
	size_t	len = 0;
	for (size_t i = 0; i < str.size(); i++) {
		if ((static_cast<unsigned char>(str[i]) & 0xC0) != 0x80)
			len++;
	}
	return (len);
}

static std::string	displaySubstr(const std::string &str, size_t n) {
	size_t	chars = 0;
	size_t	bytePos = 0;
	while (bytePos < str.size() && chars < n) {
		unsigned char	c = static_cast<unsigned char>(str[bytePos]);
		int				charBytes = 1;
		if ((c & 0x80) == 0)
			charBytes = 1;
		else if ((c & 0xE0) == 0xC0)
			charBytes = 2;
		else if ((c & 0xF0) == 0xE0)
			charBytes = 3;
		else if ((c & 0xF8) == 0xF0)
			charBytes = 4;
		bytePos += charBytes;
		chars++;
	}
	return (str.substr(0, bytePos));
}

static std::string	truncateString(const std::string &str) {
	if (displayLen(str) > 10)
		return (displaySubstr(str, 9) + ".");
	return (str);
}

static std::string	rightAlign(const std::string &str, size_t width) {
	size_t	dLen = displayLen(str);
	if (dLen >= width)
		return (str);
	return (std::string(width - dLen, ' ') + str);
}

static std::string	getInput(const std::string &prompt) {
	std::string	input;

	while (input.empty()) {
		std::cout << prompt;
		if (!std::getline(std::cin, input)) {
			std::cout << std::endl;
			std::exit(EXIT_SUCCESS);
		}
		if (input.empty())
			std::cout << "Field cannot be empty. Please try again." << std::endl;
	}
	return (input);
}

static std::string	getPhoneInput(const std::string &prompt) {
	std::string	input;

	while (true) {
		input = getInput(prompt);
		bool valid = true;
		for (size_t i = 0; i < input.size(); i++) {
			if (!std::isdigit(static_cast<unsigned char>(input[i]))) {
				valid = false;
				break ;
			}
		}
		if (valid)
			return (input);
		std::cout << "Only numbers accepted. Please try again." << std::endl;
		input.clear();
	}
}

void	PhoneBook::addContact(void) {
	Contact	newContact;

	newContact.setFirstName(getInput("First name: "));
	newContact.setLastName(getInput("Last name: "));
	newContact.setNickname(getInput("Nickname: "));
	newContact.setPhoneNumber(getPhoneInput("Phone number: "));
	newContact.setDarkestSecret(getInput("Darkest secret: "));

	this->_contacts[this->_index] = newContact;
	this->_index = (this->_index + 1) % 8;
	if (this->_count < 8)
		this->_count++;

	std::cout << "Contact added successfully!" << std::endl;
}

void	PhoneBook::searchContact(void) const {
	if (this->_count == 0) {
		std::cout << "PhoneBook is empty!" << std::endl;
		return ;
	}

	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < this->_count; i++) {
		std::cout << std::setw(10) << i << "|";
		std::cout << rightAlign(truncateString(this->_contacts[i].getFirstName()), 10) << "|";
		std::cout << rightAlign(truncateString(this->_contacts[i].getLastName()), 10) << "|";
		std::cout << rightAlign(truncateString(this->_contacts[i].getNickname()), 10) << std::endl;
	}

	std::string	indexStr;
	std::cout << "Enter index: ";
	if (!std::getline(std::cin, indexStr)) {
		std::cout << std::endl;
		return ;
	}

	std::stringstream	ss(indexStr);
	int					index;

	if (!(ss >> index) || !ss.eof() || index < 0 || index >= this->_count) {
		std::cout << "Invalid index!" << std::endl;
		return ;
	}

	std::cout << "First name: " << this->_contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << this->_contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << this->_contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: " << this->_contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->_contacts[index].getDarkestSecret() << std::endl;
}

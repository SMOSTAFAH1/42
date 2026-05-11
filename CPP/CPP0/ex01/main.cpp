#include "PhoneBook.hpp"

int	main(void) {
	PhoneBook	phoneBook;
	std::string	command;

	std::cout << "Welcome to the PhoneBook!" << std::endl;
	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;

	while (true) {
		std::cout << "> ";
		if (!std::getline(std::cin, command)) {
			std::cout << std::endl;
			break ;
		}

		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "EXIT")
			break ;
		else if (!command.empty())
			std::cout << "Invalid command! Use: ADD, SEARCH, or EXIT" << std::endl;
	}
	std::cout << "Goodbye!" << std::endl;
	return 0;
}

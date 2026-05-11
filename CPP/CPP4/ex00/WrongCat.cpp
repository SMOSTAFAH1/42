#include "WrongCat.hpp"

// Constructor
WrongCat::WrongCat() {
	_type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

// Copy constructor
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << "WrongCat copy constructor called" << std::endl;
}

// Assignment operator
WrongCat& WrongCat::operator=(const WrongCat& other) {
	std::cout << "WrongCat assignment operator called" << std::endl;
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	return *this;
}

// Destructor
WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

// Member functions
void WrongCat::makeSound() const {
	std::cout << "Wrong Meow! Wrong Meow!" << std::endl;
}

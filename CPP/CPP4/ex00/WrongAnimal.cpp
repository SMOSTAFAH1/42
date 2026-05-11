#include "WrongAnimal.hpp"

// Constructor
WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout << "WrongAnimal constructor called" << std::endl;
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

// Assignment operator
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

// Destructor
WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

// Member functions
void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal makes a generic sound" << std::endl;
}

std::string WrongAnimal::getType() const {
	return _type;
}

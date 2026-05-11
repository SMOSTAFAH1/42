#include "Animal.hpp"

// Constructor
AAnimal::AAnimal() : _type("AAnimal") {
	std::cout << "AAnimal constructor called" << std::endl;
}

// Copy constructor
AAnimal::AAnimal(const AAnimal& other) : _type(other._type) {
	std::cout << "AAnimal copy constructor called" << std::endl;
}

// Assignment operator
AAnimal& AAnimal::operator=(const AAnimal& other) {
	std::cout << "AAnimal assignment operator called" << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

// Destructor
AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const {
	return _type;
}

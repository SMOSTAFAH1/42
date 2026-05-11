#include "Animal.hpp"

// Constructor
Animal::Animal() : _type("Animal") {
	std::cout << "Animal constructor called" << std::endl;
}

// Copy constructor
Animal::Animal(const Animal& other) : _type(other._type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

// Assignment operator
Animal& Animal::operator=(const Animal& other) {
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

// Destructor
Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

// Member functions
void Animal::makeSound() const {
	std::cout << "Animal makes a generic sound" << std::endl;
}

std::string Animal::getType() const {
	return _type;
}

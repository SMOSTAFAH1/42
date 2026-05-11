#include "Dog.hpp"

// Constructor
Dog::Dog() {
	_type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

// Copy constructor
Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
}

// Assignment operator
Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

// Destructor
Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

// Member functions
void Dog::makeSound() const {
	std::cout << "Woof! Woof!" << std::endl;
}

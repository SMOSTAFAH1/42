#include "Dog.hpp"

// Constructor
Dog::Dog() : _brain(new Brain()) {
	_type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

// Copy constructor (DEEP COPY)
Dog::Dog(const Dog& other) : AAnimal(other), _brain(new Brain(*other._brain)) {
	std::cout << "Dog copy constructor called" << std::endl;
}

// Assignment operator (DEEP COPY)
Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other) {
		AAnimal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return *this;
}

// Destructor
Dog::~Dog() {
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}

// Member functions
void Dog::makeSound() const {
	std::cout << "Woof! Woof!" << std::endl;
}

Brain* Dog::getBrain() const {
	return _brain;
}

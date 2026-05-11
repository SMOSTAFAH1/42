#include "Cat.hpp"

// Constructor
Cat::Cat() : _brain(new Brain()) {
	_type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

// Copy constructor (DEEP COPY)
Cat::Cat(const Cat& other) : Animal(other), _brain(new Brain(*other._brain)) {
	std::cout << "Cat copy constructor called" << std::endl;
}

// Assignment operator (DEEP COPY)
Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return *this;
}

// Destructor
Cat::~Cat() {
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

// Member functions
void Cat::makeSound() const {
	std::cout << "Meow! Meow!" << std::endl;
}

Brain* Cat::getBrain() const {
	return _brain;
}

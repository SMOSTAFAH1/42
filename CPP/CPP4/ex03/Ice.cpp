#include "Ice.hpp"

// Constructor
Ice::Ice() : AMateria("ice") {
}

// Copy constructor
Ice::Ice(const Ice& other) : AMateria(other) {
}

// Assignment operator
Ice& Ice::operator=(const Ice& other) {
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
}

// Destructor
Ice::~Ice() {
}

// Member functions
AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

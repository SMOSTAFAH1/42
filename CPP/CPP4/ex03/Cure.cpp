#include "Cure.hpp"

// Constructor
Cure::Cure() : AMateria("cure") {
}

// Copy constructor
Cure::Cure(const Cure& other) : AMateria(other) {
}

// Assignment operator
Cure& Cure::operator=(const Cure& other) {
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
}

// Destructor
Cure::~Cure() {
}

// Member functions
AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

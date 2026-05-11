#include "AMateria.hpp"

// Constructor
AMateria::AMateria(std::string const & type) : _type(type) {
}

// Copy constructor
AMateria::AMateria(const AMateria& other) : _type(other._type) {
}

// Assignment operator
AMateria& AMateria::operator=(const AMateria& other) {
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

// Destructor
AMateria::~AMateria() {
}

// Member functions
std::string const & AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
	(void)target;
}

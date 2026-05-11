#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
public:
	// Constructor
	Cure();
	
	// Copy constructor
	Cure(const Cure& other);
	
	// Assignment operator
	Cure& operator=(const Cure& other);
	
	// Destructor
	~Cure();

	// Member functions
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif

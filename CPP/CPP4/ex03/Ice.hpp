#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
public:
	// Constructor
	Ice();
	
	// Copy constructor
	Ice(const Ice& other);
	
	// Assignment operator
	Ice& operator=(const Ice& other);
	
	// Destructor
	~Ice();

	// Member functions
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>

class ICharacter;

class AMateria {
protected:
	std::string _type;

public:
	// Constructor
	AMateria(std::string const & type);
	
	// Copy constructor
	AMateria(const AMateria& other);
	
	// Assignment operator
	AMateria& operator=(const AMateria& other);
	
	// Destructor
	virtual ~AMateria();

	// Member functions
	std::string const & getType() const;
	
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
private:
	AMateria* _templates[4];

public:
	// Constructor
	MateriaSource();
	
	// Copy constructor
	MateriaSource(const MateriaSource& other);
	
	// Assignment operator
	MateriaSource& operator=(const MateriaSource& other);
	
	// Destructor
	~MateriaSource();

	// Member functions
	void learnMateria(AMateria* m);
	AMateria* createMateria(std::string const & type);
};

#endif

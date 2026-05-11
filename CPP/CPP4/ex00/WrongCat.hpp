#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	// Constructor
	WrongCat();
	
	// Copy constructor
	WrongCat(const WrongCat& other);
	
	// Assignment operator
	WrongCat& operator=(const WrongCat& other);
	
	// Destructor
	~WrongCat();

	// Member functions (NOT VIRTUAL)
	void makeSound() const;
};

#endif

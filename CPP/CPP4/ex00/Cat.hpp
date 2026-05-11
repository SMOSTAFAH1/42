#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
public:
	// Constructor
	Cat();
	
	// Copy constructor
	Cat(const Cat& other);
	
	// Assignment operator
	Cat& operator=(const Cat& other);
	
	// Destructor
	~Cat();

	// Member functions
	void makeSound() const;
};

#endif

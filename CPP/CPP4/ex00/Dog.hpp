#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
	// Constructor
	Dog();
	
	// Copy constructor
	Dog(const Dog& other);
	
	// Assignment operator
	Dog& operator=(const Dog& other);
	
	// Destructor
	~Dog();

	// Member functions
	void makeSound() const;
};

#endif

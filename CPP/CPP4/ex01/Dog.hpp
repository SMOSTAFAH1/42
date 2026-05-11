#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
	Brain* _brain;

public:
	// Constructor
	Dog();
	
	// Copy constructor (DEEP COPY)
	Dog(const Dog& other);
	
	// Assignment operator (DEEP COPY)
	Dog& operator=(const Dog& other);
	
	// Destructor
	~Dog();

	// Member functions
	void makeSound() const;
	Brain* getBrain() const;
};

#endif

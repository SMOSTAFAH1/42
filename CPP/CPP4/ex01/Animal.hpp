#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
protected:
	std::string _type;

public:
	// Constructor
	Animal();
	
	// Copy constructor
	Animal(const Animal& other);
	
	// Assignment operator
	Animal& operator=(const Animal& other);
	
	// Destructor (VIRTUAL - critical for polymorphism)
	virtual ~Animal();

	// Member functions
	virtual void makeSound() const;
	std::string getType() const;
};

#endif

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal {
protected:
	std::string _type;

public:
	// Constructor
	AAnimal();
	
	// Copy constructor
	AAnimal(const AAnimal& other);
	
	// Assignment operator
	AAnimal& operator=(const AAnimal& other);
	
	// Destructor (VIRTUAL - critical for polymorphism)
	virtual ~AAnimal();

	// Member functions (PURE VIRTUAL - makes class abstract)
	virtual void makeSound() const = 0;
	std::string getType() const;
};

#endif

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal {
protected:
	std::string _type;

public:
	// Constructor
	WrongAnimal();
	
	// Copy constructor
	WrongAnimal(const WrongAnimal& other);
	
	// Assignment operator
	WrongAnimal& operator=(const WrongAnimal& other);
	
	// Destructor (NOT VIRTUAL - to demonstrate wrong behavior)
	~WrongAnimal();

	// Member functions (NOT VIRTUAL - to demonstrate wrong behavior)
	void makeSound() const;
	std::string getType() const;
};

#endif

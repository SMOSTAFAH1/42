#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
	Brain* _brain;

public:
	// Constructor
	Cat();
	
	// Copy constructor (DEEP COPY)
	Cat(const Cat& other);
	
	// Assignment operator (DEEP COPY)
	Cat& operator=(const Cat& other);
	
	// Destructor
	~Cat();

	// Member functions
	void makeSound() const;
	Brain* getBrain() const;
};

#endif

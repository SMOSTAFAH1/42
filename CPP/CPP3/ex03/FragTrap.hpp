#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
	// Constructor
	FragTrap(std::string name);
	
	// Copy constructor
	FragTrap(const FragTrap& other);
	
	// Assignment operator
	FragTrap& operator=(const FragTrap& other);
	
	// Destructor
	~FragTrap();

	// Special member function
	void highFivesGuys(void);
};

#endif

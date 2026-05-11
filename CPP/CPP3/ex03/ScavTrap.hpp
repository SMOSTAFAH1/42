#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
	// Constructor
	ScavTrap(std::string name);
	
	// Copy constructor
	ScavTrap(const ScavTrap& other);
	
	// Assignment operator
	ScavTrap& operator=(const ScavTrap& other);
	
	// Destructor
	~ScavTrap();

	// Override attack
	void attack(const std::string& target);
	
	// Special member function
	void guardGate();
};

#endif

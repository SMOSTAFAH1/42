#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
	std::string _name;

public:
	// Constructor
	DiamondTrap(std::string name);
	
	// Copy constructor
	DiamondTrap(const DiamondTrap& other);
	
	// Assignment operator
	DiamondTrap& operator=(const DiamondTrap& other);
	
	// Destructor
	~DiamondTrap();

	// Use ScavTrap's attack
	using ScavTrap::attack;
	
	// Special member function
	void whoAmI();
};

#endif

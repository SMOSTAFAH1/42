#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
protected:
	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;

public:
	// Constructor
	ClapTrap(std::string name);
	
	// Copy constructor
	ClapTrap(const ClapTrap& other);
	
	// Assignment operator
	ClapTrap& operator=(const ClapTrap& other);
	
	// Destructor
	~ClapTrap();

	// Member functions
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif

#include "DiamondTrap.hpp"

// Constructor
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
	// HP from FragTrap (100)
	_hitPoints = FragTrap::_hitPoints;
	// EP from ScavTrap (50)
	_energyPoints = ScavTrap::_energyPoints;
	// AD from FragTrap (30)
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << _name << " constructor called" << std::endl;
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

// Assignment operator
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
		_name = other._name;
	}
	return *this;
}

// Destructor
DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << _name << " destructor called" << std::endl;
}

// Who am I
void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name: " << _name << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}

#include "ClapTrap.hpp"

// Constructor
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

// Assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap assignment operator called" << std::endl;
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

// Destructor
ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

// Attack
void ClapTrap::attack(const std::string& target) {
	if (_energyPoints > 0 && _hitPoints > 0) {
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target 
				  << ", causing " << _attackDamage << " points of damage!" << std::endl;
	} else
		std::cout << "ClapTrap " << _name << " cannot attack (no energy or hit points left)!" << std::endl;
}

// Take damage
void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints > 0) {
		_hitPoints -= amount;
		if (_hitPoints < 0)
			_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " takes " << amount 
				  << " points of damage! Hit points: " << _hitPoints << std::endl;
	} else
		std::cout << "ClapTrap " << _name << " is already destroyed!" << std::endl;
}

// Be repaired
void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints > 0 && _hitPoints > 0) {
		_energyPoints--;
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " is repaired for " << amount 
				  << " points! Hit points: " << _hitPoints << std::endl;
	} else
		std::cout << "ClapTrap " << _name << " cannot be repaired (no energy or already destroyed)!" << std::endl;
}

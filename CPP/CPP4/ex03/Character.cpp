#include "Character.hpp"

// Constructor
Character::Character(std::string const & name) : _name(name) {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

// Copy constructor (DEEP COPY)
Character::Character(const Character& other) : _name(other._name) {
	for (int i = 0; i < 4; i++) {
		if (other._inventory[i] != NULL) {
			_inventory[i] = other._inventory[i]->clone();
		} else {
			_inventory[i] = NULL;
		}
	}
}

// Assignment operator (DEEP COPY)
Character& Character::operator=(const Character& other) {
	if (this != &other) {
		_name = other._name;
		// Delete old inventory
		for (int i = 0; i < 4; i++) {
			if (_inventory[i] != NULL) {
				delete _inventory[i];
			}
		}
		// Clone new inventory
		for (int i = 0; i < 4; i++) {
			if (other._inventory[i] != NULL) {
				_inventory[i] = other._inventory[i]->clone();
			} else {
				_inventory[i] = NULL;
			}
		}
	}
	return *this;
}

// Destructor
Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] != NULL) {
			delete _inventory[i];
		}
	}
}

// Member functions
std::string const & Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	if (m == NULL) {
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			return;
		}
	}
	// Inventory is full, delete the materia to prevent memory leak
	delete m;
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4) {
		_inventory[idx] = NULL;  // Set to NULL but DO NOT delete
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && _inventory[idx] != NULL) {
		_inventory[idx]->use(target);
	}
}

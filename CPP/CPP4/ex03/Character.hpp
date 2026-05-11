#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
private:
	std::string _name;
	AMateria* _inventory[4];

public:
	// Constructor
	Character(std::string const & name);
	
	// Copy constructor (DEEP COPY)
	Character(const Character& other);
	
	// Assignment operator (DEEP COPY)
	Character& operator=(const Character& other);
	
	// Destructor
	~Character();

	// Member functions
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif

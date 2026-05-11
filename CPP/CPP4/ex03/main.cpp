#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main() {
	std::cout << "=== Subject tests ===" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;
	
	std::cout << "\n=== Additional tests ===" << std::endl;
	
	std::cout << "\n--- Test: Full inventory ---" << std::endl;
	IMateriaSource* src2 = new MateriaSource();
	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());
	
	ICharacter* hero = new Character("hero");
	
	// Fill inventory (only 4 slots available)
	for (int i = 0; i < 4; i++) {
		tmp = src2->createMateria("ice");
		hero->equip(tmp);
	}
	
	// Try to equip a 5th item (will be automatically deleted by Character::equip)
	std::cout << "Trying to equip 5th item (should be deleted automatically):" << std::endl;
	tmp = src2->createMateria("ice");
	hero->equip(tmp);
	
	std::cout << "\n--- Test: Use all slots ---" << std::endl;
	ICharacter* target = new Character("target");
	for (int i = 0; i < 4; i++) {
		hero->use(i, *target);
	}
	
	std::cout << "\n--- Test: Deep copy ---" << std::endl;
	Character* original = new Character("original");
	tmp = src2->createMateria("cure");
	original->equip(tmp);
	tmp = src2->createMateria("ice");
	original->equip(tmp);
	
	Character* copy = new Character(*original);
	std::cout << "Original uses materia:" << std::endl;
	original->use(0, *target);
	original->use(1, *target);
	
	std::cout << "Copy uses materia:" << std::endl;
	copy->use(0, *target);
	copy->use(1, *target);
	
	std::cout << "\n--- Test: Unequip (no delete) ---" << std::endl;
	Character* testChar = new Character("test");
	// Important: unequip() sets the slot to NULL but does NOT delete the materia
	// The caller is responsible for tracking and deleting unequipped materias
	AMateria* unequipped = src2->createMateria("ice");
	testChar->equip(unequipped);
	testChar->unequip(0);  // Sets to NULL but doesn't delete
	delete unequipped;  // We need to manually delete the unequipped materia
	
	std::cout << "\n--- Cleanup ---" << std::endl;
	delete testChar;
	delete original;
	delete copy;
	delete target;
	delete hero;
	delete src2;
	
	return 0;
}

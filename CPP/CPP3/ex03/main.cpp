#include "DiamondTrap.hpp"

int main() {
	std::cout << "=== Test 1: DiamondTrap creation and destruction ===" << std::endl;
	{
		DiamondTrap diamond("DT-01");
	}
	std::cout << std::endl;

	std::cout << "=== Test 2: DiamondTrap whoAmI ===" << std::endl;
	{
		DiamondTrap diamond("DT-02");
		diamond.whoAmI();
	}
	std::cout << std::endl;

	std::cout << "=== Test 3: DiamondTrap attack (from ScavTrap) ===" << std::endl;
	{
		DiamondTrap diamond("DT-03");
		diamond.attack("Enemy");
		diamond.whoAmI();
	}
	std::cout << std::endl;

	std::cout << "=== Test 4: DiamondTrap stats (HP=100 from FragTrap, EP=50 from ScavTrap, AD=30 from FragTrap) ===" << std::endl;
	{
		DiamondTrap diamond("DT-04");
		std::cout << "Testing HP (should be 100):" << std::endl;
		diamond.takeDamage(60);
		diamond.attack("Enemy");
		diamond.takeDamage(40);
		diamond.attack("Enemy"); // Should not be able to attack (dead)
		
		std::cout << "\nCreating new DiamondTrap for energy test:" << std::endl;
		DiamondTrap diamond2("DT-05");
		std::cout << "Testing EP (should be 50):" << std::endl;
		for (int i = 0; i < 5; i++)
			diamond2.attack("Enemy");
		
		std::cout << "\nTesting AD (should be 30) - see attack messages above" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== Test 5: DiamondTrap inherited methods ===" << std::endl;
	{
		DiamondTrap diamond("DT-06");
		diamond.attack("Enemy");
		diamond.takeDamage(20);
		diamond.beRepaired(15);
		diamond.guardGate();       // From ScavTrap
		diamond.highFivesGuys();   // From FragTrap
		diamond.whoAmI();          // From DiamondTrap
	}
	std::cout << std::endl;

	std::cout << "=== Test 6: Copy constructor and assignment ===" << std::endl;
	{
		DiamondTrap diamond1("DT-07");
		diamond1.attack("Enemy");
		
		DiamondTrap diamond2(diamond1); // Copy constructor
		diamond2.whoAmI();
		
		DiamondTrap diamond3("DT-08");
		diamond3 = diamond1; // Assignment operator
		diamond3.whoAmI();
	}
	std::cout << std::endl;

	return 0;
}

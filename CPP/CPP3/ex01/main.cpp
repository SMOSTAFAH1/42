#include "ScavTrap.hpp"

int main() {
	std::cout << "=== Test 1: ScavTrap creation and destruction ===" << std::endl;
	{
		ScavTrap scav("ST-01");
	}
	std::cout << std::endl;

	std::cout << "=== Test 2: ScavTrap attack and guardGate ===" << std::endl;
	{
		ScavTrap scav("ST-02");
		scav.attack("Target-A");
		scav.guardGate();
		scav.takeDamage(30);
		scav.beRepaired(20);
	}
	std::cout << std::endl;

	std::cout << "=== Test 3: ScavTrap stats (HP=100, EP=50, AD=20) ===" << std::endl;
	{
		ScavTrap scav("ST-03");
		// Test high HP
		scav.takeDamage(50);
		scav.takeDamage(50);
		scav.attack("Enemy");
		
		// Test energy with multiple attacks
		std::cout << "\nTesting energy (should have 50):" << std::endl;
		for (int i = 0; i < 5; i++)
			scav.attack("Enemy");
	}
	std::cout << std::endl;

	std::cout << "=== Test 4: Copy constructor and assignment ===" << std::endl;
	{
		ScavTrap scav1("ST-04");
		scav1.attack("Enemy");
		
		ScavTrap scav2(scav1); // Copy constructor
		scav2.guardGate();
		
		ScavTrap scav3("ST-05");
		scav3 = scav1; // Assignment operator
		scav3.attack("Enemy");
	}
	std::cout << std::endl;

	std::cout << "=== Test 5: Mixed ClapTrap and ScavTrap ===" << std::endl;
	{
		ClapTrap clap("CT-01");
		ScavTrap scav("ST-06");
		
		clap.attack("ScavTrap");
		scav.attack("ClapTrap");
		scav.guardGate();
	}
	std::cout << std::endl;

	return 0;
}

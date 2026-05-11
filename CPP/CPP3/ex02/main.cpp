#include "FragTrap.hpp"

int main() {
	std::cout << "=== Test 1: FragTrap creation and destruction ===" << std::endl;
	{
		FragTrap frag("FT-01");
	}
	std::cout << std::endl;

	std::cout << "=== Test 2: FragTrap attack and highFivesGuys ===" << std::endl;
	{
		FragTrap frag("FT-02");
		frag.attack("Target-A");
		frag.highFivesGuys();
		frag.takeDamage(40);
		frag.beRepaired(25);
	}
	std::cout << std::endl;

	std::cout << "=== Test 3: FragTrap stats (HP=100, EP=100, AD=30) ===" << std::endl;
	{
		FragTrap frag("FT-03");
		// Test high HP
		frag.takeDamage(60);
		frag.attack("Enemy");
		frag.takeDamage(40);
		frag.attack("Enemy");
		
		// Test high energy with multiple attacks
		std::cout << "\nTesting energy (should have 100):" << std::endl;
		for (int i = 0; i < 5; i++)
			frag.attack("Enemy");
	}
	std::cout << std::endl;

	std::cout << "=== Test 4: Copy constructor and assignment ===" << std::endl;
	{
		FragTrap frag1("FT-04");
		frag1.attack("Enemy");
		
		FragTrap frag2(frag1); // Copy constructor
		frag2.highFivesGuys();
		
		FragTrap frag3("FT-05");
		frag3 = frag1; // Assignment operator
		frag3.attack("Enemy");
	}
	std::cout << std::endl;

	std::cout << "=== Test 5: Mixed ClapTrap and FragTrap ===" << std::endl;
	{
		ClapTrap clap("CT-01");
		FragTrap frag("FT-06");
		
		clap.attack("FragTrap");
		frag.attack("ClapTrap");
		frag.highFivesGuys();
	}
	std::cout << std::endl;

	return 0;
}

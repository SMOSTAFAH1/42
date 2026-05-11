#include "ClapTrap.hpp"

int main() {
	std::cout << "=== Test 1: Basic ClapTrap creation and destruction ===" << std::endl;
	{
		ClapTrap clap("CT-01");
	}
	std::cout << std::endl;

	std::cout << "=== Test 2: Attack, take damage, and repair ===" << std::endl;
	{
		ClapTrap clap("CT-02");
		clap.attack("Target-A");
		clap.takeDamage(3);
		clap.beRepaired(5);
		clap.attack("Target-B");
	}
	std::cout << std::endl;

	std::cout << "=== Test 3: Energy depletion ===" << std::endl;
	{
		ClapTrap clap("CT-03");
		for (int i = 0; i < 11; i++)
			clap.attack("Enemy");
	}
	std::cout << std::endl;

	std::cout << "=== Test 4: Death and damage ===" << std::endl;
	{
		ClapTrap clap("CT-04");
		clap.takeDamage(5);
		clap.takeDamage(5);
		clap.takeDamage(3); // Already dead
		clap.attack("Enemy"); // Cannot attack
		clap.beRepaired(5); // Cannot repair
	}
	std::cout << std::endl;

	std::cout << "=== Test 5: Copy constructor and assignment operator ===" << std::endl;
	{
		ClapTrap clap1("CT-05");
		clap1.attack("Enemy");
		
		ClapTrap clap2(clap1); // Copy constructor
		clap2.attack("Enemy");
		
		ClapTrap clap3("CT-06");
		clap3 = clap1; // Assignment operator
		clap3.attack("Enemy");
	}
	std::cout << std::endl;

	return 0;
}
